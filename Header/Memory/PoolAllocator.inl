template <typename T>
/* explicit */ inline PoolAllocator<T>::PoolAllocator()
{
    // None
}

template <typename T>
inline PoolAllocator<T>::~PoolAllocator()
{
    for(unsigned i = 0; i < m_resources.size(); ++i)
    {
        delete m_resources[i];
    }
}

template <typename T>
void PoolAllocator<T>::Init(unsigned int size)
{
    for(unsigned int i = 0; i < size; ++i)
        m_resources.push_back(new Resource<T>());
}

template <typename T>
T * PoolAllocator<T>::Allocate()
{
    for(Resource<T> * res : m_resources)
    {
        if(res->IsAvailable())
        {
            res->SetAvailable(false);
            return res->GetResource();
        }
    }

    // Need to allocate a new one
    m_resources.push_back(new Resource<T>());
    m_resources.back()->SetAvailable(false);

    return m_resources.back()->GetResource();
}

template <typename T>
void PoolAllocator<T>::Deallocate(T * resource)
{
    for(Resource<T> * res : m_resources)
    {
        if(res->GetResource() == resource)
        {
            res->SetAvailable(true);
            break;
        }
    }
}