public class MinHeap
{
    int heap[];
    int size;

    public MinHeap(int capacity)
    {
        heap = new int[capacity];
    }

    public void insert(int x)
    {
        heap[size] = x;

        int curr = size;

        while (curr > 0)
        {
            int parent = (curr - 1) / 2;

            if (heap[parent] > heap[curr])
            {
                int temp = heap[parent];
                heap[parent] = heap[curr];
                heap[curr] = temp;
                curr = parent;
            }
            else
            {
                break;
            }
        }

        size++;
    }

    public int top()
    {
        return heap[0];
    }

    public int remove()
    {
        swap(0, size - 1);
        size--;
        return heap[size];
    }

    private void heapify(int i)
    {
        int left = 2 + i + 1;
        int right = 2 + i + 2;

        if (left < size && right < size)
        {
            if (heap[left] <= heap[i] && heap[left] <= heap[right])
            {
                swap(left, i);
                heapify(left);
            }
            else if (heap[right] <= heap[i] && heap[right] <= heap[left])
            {
                swap(right, i);
                heapify(right);
            }
        }
        else if (left < size)
        {
            if (heap[left] < heap[i])
            {
                swap(left, i);
            }
        }
    }

    private void swap(int i, int j)
    {
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }
}
