/*
 * Example of `object pool' design pattern
 * Copyright (C) 2011 Radek Pazdera
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <memory>
#include <string>
#include <iostream>
#include <list>

class Resource
{
    int value;

    public:
        Resource()
        {
            value = 0;
        }

        void reset()
        {
            value = 0;
        }

        int getValue()
        {
            return value;
        }

        void setValue(int number)
        {
            value = number;
        }
};

/* Note, that this class is a singleton. */
class ObjectPool
{
    private:
        std::list<std::unique_ptr<Resource> > resources;

        static ObjectPool* instance;
        ObjectPool() {}

    public:
        /**
         * Static method for accessing class instance.
         * Part of Singleton design pattern.
         *
         * @return ObjectPool instance.
         */
        static ObjectPool* getInstance()
        {
            if (instance == 0)
            {
                instance = new ObjectPool;
            }
            return instance;
        }

        /**
         * Returns instance of Resource.
         *
         * New resource will be created if all the resources
         * were used at the time of the request.
         *
         * @return Resource instance.
         */
        std::unique_ptr<Resource> getResource()
        {
            if (resources.empty())
            {
                std::cout << "Creating new." << std::endl;
                return std::unique_ptr<Resource>(new Resource);
            }
            else
            {
                std::cout << "Reusing existing." << std::endl;
                auto& resource = resources.front();
                resources.pop_front();
                return std::move(resource);
            }
        }

        /**
         * Return resource back to the pool.
         *
         * The resource must be initialized back to
         * the default settings before someone else
         * attempts to use it.
         *
         * @param object Resource instance.
         * @return void
         */
        void returnResource(std::unique_ptr<Resource> object)
        {
            object->reset();
            resources.push_back(std::move(object));
        }
};

ObjectPool* ObjectPool::instance = 0;


int main()
{
    ObjectPool* pool = ObjectPool::getInstance();
    std::unique_ptr<Resource> one;
    std::unique_ptr<Resource> two;

    /* Resources will be created. */
    one = pool->getResource();
    one->setValue(10);
    std::cout << "one = " << one->getValue() << " [" << one << "]" << std::endl;

    two = pool->getResource();
    two->setValue(20);
    std::cout << "two = " << two->getValue() << " [" << two << "]" << std::endl;

    pool->returnResource(std::move(one));
    pool->returnResource(std::move(two));

    /* Resources will be reused.
     * Notice that the value of both resources were reset back to zero.
     */
    one = pool->getResource();
    std::cout << "one = " << one->getValue() << " [" << one << "]" << std::endl;

    two = pool->getResource();
    std::cout << "two = " << two->getValue() << " [" << two << "]" << std::endl;

    return 0;
}
