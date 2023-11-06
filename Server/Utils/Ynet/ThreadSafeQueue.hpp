#ifndef YNET_THREAD_SAFE_QUEUE_HPP
#define YNET_THREAD_SAFE_QUEUE_HPP

#include <condition_variable>
#include <mutex>
#include <deque>

namespace Ynet{
    template<typename T>
    class ThreadSafeQueue 
    {
    public:
        using value_type = typename std::deque<T>::value_type;
        using size_type = typename std::deque<T>::size_type;
        using reference = value_type&;
        using const_reference = const value_type&;

    public:
        ThreadSafeQueue() = default;
        ~ThreadSafeQueue() { clear(); }
        ThreadSafeQueue(const ThreadSafeQueue& ) = delete;
        ThreadSafeQueue& operator=(const ThreadSafeQueue& ) = delete;

        const_reference front(){
            std::scoped_lock lock(queueMutex);
            return m_data.front();
        }

        const_reference back(){
            std::scoped_lock lock(queueMutex);
            return m_data.back();
        }

        bool empty() {
            std::scoped_lock lock(queueMutex);
            return m_data.empty();
        }

        void push_back(const_reference elem){
            std::scoped_lock lock(queueMutex);
            m_data.push_back(elem);

            std::unique_lock<std::mutex> ul(muxBlocking);
            cvBlocking.notify_one();

       }
        void push_front(const_reference elem){
            std::scoped_lock lock(queueMutex);
            m_data.push_front(elem);

            std::unique_lock<std::mutex> ul(muxBlocking);
            cvBlocking.notify_one();
        }

        size_type size(){
            std::scoped_lock lock(queueMutex);
            return m_data.size();
        }

        void clear(){
            std::scoped_lock lock(queueMutex);
            m_data.clear();
        }
        /// Pops, also returns value 
        value_type pop_back(){
            std::scoped_lock lock(queueMutex);
            auto value = std::move(m_data.back());
            m_data.pop_back();
            return value;
        }
        /// Pops, also returns value 
        value_type pop_front(){
            std::scoped_lock lock(queueMutex);
            auto value = std::move(m_data.front());
            m_data.pop_front();
            return value;
        }

        void wait(){
            while(empty()){
                std::unique_lock<std::mutex> ul(muxBlocking);
                cvBlocking.wait(ul);
            }
        }

    private:
        std::mutex queueMutex;
        std::deque<T> m_data;

        std::condition_variable cvBlocking;
        std::mutex muxBlocking;

    };

}

#endif //YNET_THREAD_SAFE_QUEUE_HPP