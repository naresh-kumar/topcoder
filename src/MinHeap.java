public class MinHeap<T extends Comparable<T>>
{
    T[] heap;
    int size;

    public MinHeap(T[] heap)
    {
        this.heap = heap;
    }

    public void insert(T x)
    {
        heap[size] = x;

        int curr = size;

        while (curr > 0)
        {
            int parent = (curr - 1) / 2;

            if (heap[parent].compareTo(heap[curr]) > 0)
            {
                swap(parent, curr);
                curr = parent;
            }
            else
            {
                break;
            }
        }

        size++;
    }

    public T top()
    {
        return heap[0];
    }

    public T remove()
    {
        swap(0, size - 1);
        size--;
        heapify(0);
        return heap[size];
    }

    private void heapify(int i)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && right < size)
        {
            if (heap[left].compareTo(heap[i]) <= 0 && heap[left].compareTo(heap[right]) <= 0)
            {
                swap(left, i);
                heapify(left);
            }
            else if (heap[right].compareTo(heap[i]) <= 0 && heap[right].compareTo(heap[left]) <= 0)
            {
                swap(right, i);
                heapify(right);
            }
        }
        else if (left < size)
        {
            if (heap[left].compareTo(heap[i]) < 0)
            {
                swap(left, i);
            }
        }
    }

    private void swap(int i, int j)
    {
        T temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }
}
