

template <typename T>
void MinHeap<T>::siftUp(int i) {
    
    while (i > 0) {
        int p = parent(i);
        if (data[i] < data[p]) {
            std::swap(data[i], data[p]);
            i = p;
        } else {
            break;
        }
    }
}

template <typename T>
void MinHeap<T>::siftDown(int i) {
    
    int n = static_cast<int>(data.size());
    while (true) {
        int l = left(i);
        int r = right(i);
        int smallest = i;

        if (l < n && data[l] < data[smallest])
            smallest = l;
        if (r < n && data[r] < data[smallest])
            smallest = r;

        if (smallest == i)
            break;

        std::swap(data[i], data[smallest]);
        i = smallest;
    }
}

template <typename T>
void MinHeap<T>::insert(const T& value) {
    
    data.push_back(value);
    siftUp(static_cast<int>(data.size()) - 1);
}

template <typename T>
T MinHeap<T>::removeRoot() {
    if (empty())
        throw std::runtime_error("Heap is empty");

    T rootValue = data[0];
    std::swap(data[0], data.back());
    data.pop_back();

    if (!data.empty())
        siftDown(0);

    return rootValue;
}

template <typename T>
void MinHeap<T>::removeAt(int index) {
    if (index < 0 || index >= size())
        throw std::runtime_error("Invalid index");

    std::swap(data[index], data.back());
    data.pop_back();

    if (index < size()) {
      
        if (index > 0 && data[index] < data[parent(index)])
            siftUp(index);
        else
            siftDown(index);
    }
}
