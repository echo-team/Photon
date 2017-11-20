#ifdef EVENTQUEUE_H

    using namespace std;

    class EventQueue
    {
        private:
            List<void (*)(int)>* lQueue;
        public:
            void addListener(void (*listener)(int))
            {
                this->lQueue->push(listener);
            }
            void dispatch()
            {
                ListUnit<void (*)(int)>* luCurrent = this->lQueue->first;
                while (luCurrent != NULL)
                {
                    luCurrent->element(1);
                    luCurrent = luCurrent->getNext();
                }
            }
            EventQueue()
            {
                lQueue = new List<void (*)(int)>();
            }
    };

#endif
