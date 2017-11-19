#ifdef LISTUNIT_H

    template <typename tType>
    class ListUnit
    {
        private:
            ListUnit<tType>* next;
            ListUnit<tType>* previous;
        public:
            tType element;
            ListUnit(tType tElement)
            {
                this->element = tElement;
                this->next = NULL;
                this->previous = NULL;
            }
            ListUnit<tType>* getNext()
            {
                return this->next;
            }
            ListUnit<tType>* getPrevious()
            {
                return this->previous;
            }
            void setNext(ListUnit<tType>* luNext)
            {
                this->next = luNext;
            }
            void setPrevious(ListUnit<tType>* luPrevious)
            {
                this->previous = luPrevious;
            }
            ListUnit<tType>* copy()
            {
                ListUnit<tType>* luCopy = (ListUnit<tType>*)malloc(sizeof(ListUnit<tType>));
                luCopy = new ListUnit<tType>(this->element);

                return luCopy;
            }
            void copy(ListUnit<tType>* luCopy)
            {
                luCopy->element = this->element;
            }
    };

#endif
