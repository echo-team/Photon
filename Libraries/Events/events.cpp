#ifdef EVENTS_H

    class Events
    {
        private:
            EventQueue* vTypes;
            int iLength;
        public:
            Events(int iEventsAmount)
            {
                this->iLength = iEventsAmount;
                this->vTypes = (EventQueue*)malloc(sizeof(EventQueue) * this->iLength);

                for (int iCounter = 0; iCounter < this->iLength; iCounter++)
                {
                    vTypes[iCounter] = EventQueue();
                }
            }
            EventQueue operator[](int iIndex)
            {
                return vTypes[iIndex];
            }
            void dispatchEvent(int iIndex)
            {
                vTypes[iIndex].dispatch();
            }
    };

#endif
