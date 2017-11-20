#ifdef EVENTS_H

    class Events
    {
        private:
            EventQueue* vTypes;
        public:
            Events(int iEventsAmount)
            {
                vTypes = (EventQueue*)malloc(sizeof(EventQueue) * iEventsAmount);

                for (int iCounter = 0; iCounter < iEventsAmount; iCounter++)
                {
                    vTypes[iCounter] = EventQueue();
                }
            }
            EventQueue operator[](int iIndex)
            {
                return vTypes[iIndex];
            }
    };

#endif
