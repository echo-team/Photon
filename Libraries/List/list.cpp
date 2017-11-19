#ifdef LIST_H

    using namespace std;

    template <typename tType>
    class List
    {
        public:
            ListUnit<tType>* first;
            ListUnit<tType>* last;
            long int length;
            /**
             * Inserts element into eng of List
             *
             * Can take one ListUnit argument or argument of type of List elements
             */
            void push(ListUnit<tType>* luPushing)
            {
                ListUnit<tType>* luEnd = this->last;

                if (luEnd == NULL)
                {
                    this->first = luPushing;
                }
                else
                {
                    luEnd->setNext(luPushing);
                    luPushing->setPrevious(luEnd);
                }

                this->last = luPushing;
                this->length++;
            }
            void push(tType tElement)
            {
                ListUnit<tType>* luEnd = this->last;
                ListUnit<tType>* luNewEnd = (ListUnit<tType>*)malloc(sizeof(ListUnit<tType>));
                luNewEnd = new ListUnit<tType>(tElement);

                if (luEnd == NULL)
                {
                    this->first = luNewEnd;
                }
                else
                {
                    luEnd->setNext(luNewEnd);
                    luNewEnd->setPrevious(luEnd);
                }

                this->last = luNewEnd;
                this->length++;
            }
            /**
             * Copies List to another
             *
             * First parameter always must be List where to copy
             * Second two parameters can be ListUnits or ints of what to copy (from and to)
             * With no second parameters copies all List
             */
            void copy(List<tType>* lCopy, ListUnit<tType>* luFirst, ListUnit<tType>* luLast)
            {
                ListUnit<tType>* luCurrent = this->first;
                while (luCurrent != NULL && luCurrent != luLast)
                {
                    luCurrent = luCurrent->getNext();
                }

                if (lCopy->first != NULL || luCurrent == NULL)
                {
                    return;
                }

                luCurrent = luFirst;
                while (luCurrent != NULL && luCurrent != luLast)
                {
                    lCopy->push(luCurrent->copy());
                    luCurrent = luCurrent->getNext();
                }
                lCopy->push(luLast->copy());
            }
            void copy(List<tType>* lCopy, int iFirst, int iLast)
            {
                if (lCopy->first != NULL || iFirst > iLast || iFirst < 0 || iLast >= this->length)
                {
                    return;
                }

                ListUnit<tType>* luCurrent = this->onPosition(iFirst);
                int iCounter = iFirst;
                while (iCounter <= iLast)
                {
                    lCopy->push(luCurrent->copy());
                    luCurrent = luCurrent->getNext();
                    iCounter++;
                }
            }
            void copy(List<tType>* lCopy)
            {
                if (lCopy->first != NULL)
                {
                    return;
                }

                ListUnit<tType>* luCurrent = this->first;
                while (luCurrent != NULL)
                {
                    lCopy->push(luCurrent->copy());
                    luCurrent = luCurrent->getNext();
                }
            }
            /**
             * Copies List to another
             *
             * First two parameters can be ListUnits or ints of what to copy (from and to)
             * With no parameters copies all List
             *
             * Returns copy of List as pointer
             */
            List<tType>* copy(ListUnit<tType>* luFirst, ListUnit<tType>* luLast)
            {
                List<tType>* lCopy = (List<tType>*)malloc(sizeof(List<tType>));
                this->copy(lCopy, luFirst, luLast);
                return lCopy;
            }
            List<tType>* copy(int iFirst, int iLast)
            {
                List<tType>* lCopy = (List<tType>*)malloc(sizeof(List<tType>));
                this->copy(lCopy, iFirst, iLast);
                return lCopy;
            }
            List<tType>* copy()
            {
                List<tType>* lCopy = (List<tType>*)malloc(sizeof(List<tType>));
                lCopy = new List();
                this->copy(lCopy);

                return lCopy;
            }
            /**
             * Finds something in List
             *
             * First parameter can be ListUnit pointer to element from what to find, if not ListUnit pointer finds from first
             * Second or first paramenter is what to find (can be pointer to char-string, string, pointer to array, List)
             * Fird or second parameter is length of array (uses only with previous pointer to array argument)
             *
             * Returns ListUnit pointer where something was founded
             */
            ListUnit<tType>* find(ListUnit<tType>* luFrom, char* sFinding)
            {
                ListUnit<tType>* luCurrent = luFrom;
                ListUnit<tType>* luFounded;
                int iCounter = 0,
                    iLength = strlen(sFinding);

                while (luCurrent != NULL && iCounter < iLength)
                {
                    if (luCurrent->element == sFinding[iCounter])
                    {
                        if (iCounter == 0)
                        {
                            luFounded = luCurrent;
                        }
                        iCounter++;
                    }
                    else
                    {
                        iCounter = 0;
                        luFounded = NULL;
                    }

                    luCurrent = luCurrent->getNext();
                }

                if (iCounter == iLength)
                {
                    return luFounded;
                }
                else
                {
                    return NULL;
                }
            }
            ListUnit<tType>* find(ListUnit<tType>* luFrom, string sFinding)
            {
                ListUnit<tType>* luCurrent = luFrom;
                ListUnit<tType>* luFounded;
                int iCounter = 0,
                    iLength = sFinding.length();

                while (luCurrent != NULL && iCounter < iLength)
                {
                    if (luCurrent->element == sFinding[iCounter])
                    {
                        if (iCounter == 0)
                        {
                            luFounded = luCurrent;
                        }
                        iCounter++;
                    }
                    else
                    {
                        iCounter = 0;
                        luFounded = NULL;
                    }

                    luCurrent = luCurrent->getNext();
                }

                if (iCounter == iLength)
                {
                    return luFounded;
                }
                else
                {
                    return NULL;
                }
            }
            ListUnit<tType>* find(ListUnit<tType>* luFrom, tType* atFinding, int iLength)
            {
                ListUnit<tType>* luCurrent = luFrom;
                ListUnit<tType>* luFounded;
                int iCounter = 0;

                while (luCurrent != NULL && iCounter < iLength)
                {
                    if (luCurrent->element == atFinding[iCounter])
                    {
                        if (iCounter == 0)
                        {
                            luFounded = luCurrent;
                        }
                        iCounter++;
                    }
                    else
                    {
                        iCounter = 0;
                        luFounded = NULL;
                    }

                    luCurrent = luCurrent->getNext();
                }

                if (iCounter == iLength)
                {
                    return luFounded;
                }
                else
                {
                    return NULL;
                }
            }
            ListUnit<tType>* find(ListUnit<tType>* luFrom, List<tType>* lFinding)
            {
                if (lFinding == NULL)
                {
                    return NULL;
                }

                ListUnit<tType>* luCurrent = luFrom;
                ListUnit<tType>* luFinding = lFinding->first;
                ListUnit<tType>* luFounded = NULL;

                while (luCurrent != NULL && luFinding != NULL)
                {
                    if (luCurrent->element == luFinding->element)
                    {
                        if (luFounded == NULL)
                        {
                            luFounded = luCurrent;
                        }
                        luFinding = luFinding->getNext();
                    }
                    else
                    {
                        luFinding = lFinding->first;
                        luFounded = NULL;
                    }

                    luCurrent = luCurrent->getNext();
                }

                if (luFinding == NULL)
                {
                    return luFounded;
                }
                else
                {
                    return NULL;
                }
            }
            ListUnit<tType>* find(char* sFinding)
            {
                return this->find(this->first, sFinding);
            }
            ListUnit<tType>* find(string sFinding)
            {
                return this->find(this->first, sFinding);
            }
            ListUnit<tType>* find(tType* atFinding, int iLength)
            {
                return this->find(this->length, atFinding, iLength);
            }
            ListUnit<tType>* find(List<tType>* lFinding)
            {
                return this->find(this->first, lFinding);
            }
            /**
             * Finds element at number in List
             *
             * First parameter is int, number in List
             *
             * Returns ListUnit pointer on number
             */
            ListUnit<tType>* onPosition(int iIndex)
            {
                if (iIndex < 0 || iIndex >= this->length)
                {
                    return NULL;
                }

                ListUnit<tType>* luFounding = this->first;

                for (int iCounter = 0; iCounter < iIndex && luFounding != NULL; iCounter++)
                {
                    luFounding = luFounding->getNext();
                }

                return luFounding;
            }
            /**
             * Inserts something to List on given position
             *
             * First parameter can be ListUnit pointer or int index of element from what to insert, if NULL, just pushs element
             * Second parameter is what to insert (List, ListUnit, element typed of List)
             */
            void insert(ListUnit<tType>* luNext, ListUnit<tType>* luInserting)
            {
                if (luNext == NULL)
                {
                    this->push(luInserting);
                }
                else
                {
                    ListUnit<tType>* luPrevious = luNext->getPrevious();

                    if (luPrevious == NULL)
                    {
                        this->first = luInserting;
                    }
                    else
                    {
                        luPrevious->setNext(luInserting);
                    }

                    luNext->setPrevious(luInserting);
                    luInserting->setNext(luNext);
                    luInserting->setPrevious(luPrevious);
                    this->length++;
                }
            }
            void insert(ListUnit<tType>* luNext, tType tElement)
            {
                ListUnit<tType>* luInserting = (ListUnit<tType>*)malloc(sizeof(ListUnit<tType>));
                luInserting = new ListUnit<tType>(tElement);

                this->insert(luNext, luInserting);
            }
            void insert(int iIndex, ListUnit<tType>* luInserting)
            {
                ListUnit<tType>* luOnPosition = this->onPosition(iIndex);
                this->insert(luOnPosition, luInserting);
            }
            void insert(int iIndex, tType tElement)
            {
                ListUnit<tType>* luOnPosition = this->onPosition(iIndex);
                ListUnit<tType>* luInserting = (ListUnit<tType>*)malloc(sizeof(ListUnit<tType>));
                luInserting = new ListUnit<tType>(tElement);

                this->insert(luOnPosition, luInserting);
            }
            void insert(ListUnit<tType>* luNext, List<tType>* lInserting)
            {
                ListUnit<tType>* luCurrent = lInserting->first;
                while (luCurrent != NULL)
                {
                    this->insert(luNext, luCurrent->copy());
                    luCurrent = luCurrent->getNext();
                }
            }
            void insert(int iIndex, List<tType>* lInserting)
            {
                ListUnit<tType>* luOnPosition = this->onPosition(iIndex);
                this->insert(luOnPosition, lInserting);
            }
            /**
             * Removes ListUnit, part of List or all ListUnits
             *
             * To remove one ListUnit pass one argument (ListUnit or it's int index in List)
             * To remove part of List pass two parameters - start and end elements (ListUnits or their's int indexes)
             * To remove all elements in List pass nothing
             */
            void remove(ListUnit<tType>* luRemoving)
            {
                if (luRemoving == NULL)
                {
                    return;
                }

                ListUnit<tType>* luPrevious = luRemoving->getPrevious();
                ListUnit<tType>* luNext = luRemoving->getNext();
                this->length--;
                delete luRemoving;

                if (luPrevious == NULL)
                {
                    this->first = luNext;
                }
                else
                {
                    luPrevious->setNext(luNext);
                }

                if (luNext == NULL)
                {
                    this->last = luPrevious;
                }
                else
                {
                    luNext->setPrevious(luPrevious);
                }
            }
            void remove(ListUnit<tType>* luFirst, ListUnit<tType>* luLast)
            {
                if (luFirst == luLast)
                {
                    this->remove(luFirst);
                    return;
                }

                ListUnit<tType>* luCurrent = luFirst;
                while (luCurrent != luLast && luCurrent != NULL)
                {
                    luCurrent = luCurrent->getNext();
                }

                if (luCurrent == NULL)
                {
                    return;
                }
                else
                {
                    luCurrent = luFirst->getNext();
                    while (luCurrent != luLast)
                    {
                        this->remove(luCurrent);
                        luCurrent = luFirst->getNext();
                    }

                    this->remove(luFirst);
                    this->remove(luLast);
                }
            }
            void remove(int iFirst, int iLast)
            {
                if (iFirst > iLast || iLast >= this->length || iFirst < 0)
                {
                    return;
                }
                else
                {
                    ListUnit<tType>* luFirst = this->onPosition(iFirst);

                    if (iFirst == iLast)
                    {
                        this->remove(luFirst);
                        return;
                    }

                    ListUnit<tType>* luCurrent = luFirst;
                    for (int iCounter = iFirst; iCounter < iLast && luCurrent != NULL; iCounter++)
                    {
                        luCurrent = luCurrent->getNext();
                    }

                    if (luCurrent != NULL)
                    {
                        ListUnit<tType>* luLast = luCurrent;

                        luCurrent = luFirst->getNext();
                        while (luCurrent != luLast)
                        {
                            this->remove(luCurrent);
                            luCurrent = luFirst->getNext();
                        }
                        this->remove(luFirst);
                        this->remove(luLast);
                    }
                }
            }
            void remove(int iIndex)
            {
                ListUnit<tType>* luRemoving = this->onPosition(iIndex);
                this->remove(luRemoving);
            }
            /**
             * Cuts part of List to another List
             *
             * Takes two parameters start and end of new List slice (ListUnits or their's int indexes)
             *
             * Returns List with cutted elements
             */
            List<tType>* cut(ListUnit<tType>* luFirst, ListUnit<tType>* luLast)
            {
                if (luLast == NULL)
                {
                    return NULL;
                }

                ListUnit<tType>* luCurrent = luFirst;
                while (luCurrent != luLast && luCurrent != NULL)
                {
                    luCurrent = luCurrent->getNext();
                }

                if (luCurrent != luLast)
                {
                    return NULL;
                }
                else
                {
                    List<tType>* lCut = new List<tType>();
                    ListUnit<tType>* luCurrent = luFirst->getNext();

                    lCut->push(luFirst->copy());
                    while (luCurrent != luLast)
                    {
                        lCut->push(luCurrent->copy());
                        this->remove(luCurrent);
                        luCurrent = luFirst->getNext();
                    }
                    lCut->push(luLast->copy());

                    this->remove(luFirst);
                    this->remove(luLast);

                    return lCut;
                }
            }
            void remove()
            {
                this->cut(this->first, this->last);
            }
            List<tType>* cut(int iFirst, int iLast)
            {
                if (iFirst > iLast || iLast >= this->length || iFirst < 0)
                {
                    return NULL;
                }
                else
                {
                    List<tType>* lCut = new List<tType>();
                    ListUnit<tType>* luFirst = this->onPosition(iFirst);
                    ListUnit<tType>* luCurrent = luFirst->getNext();
                    int iCounter = iFirst + 1;

                    lCut->push(luFirst->copy());
                    while (iCounter <= iLast)
                    {
                        lCut->push(luCurrent->copy());
                        this->remove(luCurrent);
                        luCurrent = luFirst->getNext();
                        iCounter++;
                    }

                    this->remove(luFirst);
                    this->remove(luCurrent);

                    return lCut;
                }
            }
            /**
             * Inserts array's, chars-string's, string's, another List's or initializer's elements to this List
             * List must be empty
             *
             * First parameter is what to convert (array, string, char-string or List)
             * Second parameter is int length of array (nesessary only if first parameter is of array type)
             */
            void from(char* sConverting)
            {
                if (this->first != NULL)
                {
                    return;
                }

                for (int iCounter = 0; iCounter < strlen(sConverting); iCounter++)
                {
                    this->push(sConverting[iCounter]);
                }
            }
            void from(string sConverting)
            {
                if (this->first != NULL)
                {
                    return;
                }

                for (int iCounter = 0; iCounter < sConverting.length(); iCounter++)
                {
                    this->push(sConverting[iCounter]);
                }
            }
            void from(tType* atConverting, int iLength)
            {
                if (this->first != NULL)
                {
                    return;
                }

                for (int iCounter = 0; iCounter < iLength; iCounter++)
                {
                    this->push(atConverting[iCounter]);
                }
            }
            void from(List<tType>* lConverting)
            {
                if (this->first != NULL)
                {
                    return;
                }

                lConverting = lConverting->copy();
                this->insert((ListUnit<tType>*)NULL, lConverting);
            }
            void from(std::initializer_list<tType> ilConverting)
            {
                if (this->first != NULL)
                {
                    return;
                }

                for(auto& tItem : ilConverting)
                {
                    this->push(tItem);
                }
            }
            /**
             * Construct List from arrays, strings, char-strings, Lists and initializer_lists
             *
             * Arguments just as like as in from method
             */
            List()
            {
                this->first = NULL;
                this->last = NULL;
                this->length = 0;
            }
            List(char* sConverting)
            {
                this->first = NULL;
                this->last = NULL;
                this->length = 0;

                this->from(sConverting);
            }
            List(string sConverting)
            {
                this->first = NULL;
                this->last = NULL;
                this->length = 0;

                this->from(sConverting);
            }
            List(tType* atConverting, int iLength)
            {
                this->first = NULL;
                this->last = NULL;
                this->length = 0;

                this->from(atConverting, iLength);
            }
            List(List<tType>* lConverting)
            {
                this->first = NULL;
                this->last = NULL;
                this->length = 0;

                this->from(lConverting);
            }
            List(std::initializer_list<tType> ilConverting)
            {
                this->first = NULL;
                this->last = NULL;
                this->length = 0;

                this->from(ilConverting);
            }
            /**
             * Construct List from strings, char-strings, Lists and initializer_lists
             *
             * Arguments can be strings, char-strings, Lists and initializer_lists
             */
            void operator=(char* sConverting)
            {
                this->remove();
                this->from(sConverting);
            }
            void operator=(string sConverting)
            {
                this->remove();
                this->from(sConverting);
            }
            void operator=(List<tType>* lConverting)
            {
                this->remove();
                this->from(lConverting);
            }
            void operator=(std::initializer_list<tType> ilConverting)
            {
                this->remove();
                this->from(ilConverting);
            }
            /**
             * Adds element to List
             *
             * Argument can be a string, char-string, List, initializer_list, ListUnit and just bare elements typed as like as
             * the main List
             */
            void operator+=(List<tType>* lConcatination)
            {
                ListUnit<tType>* luCurrent = lConcatination->first;
                while (luCurrent != NULL)
                {
                    this->push(luCurrent->copy());
                    luCurrent = luCurrent->getNext();
                }
            }
            void operator+=(ListUnit<tType>* luConcatination)
            {
                this->push(luConcatination->copy());
            }
            void operator+=(char* sConcatination)
            {
                for (int iCounter = 0; sConcatination[iCounter] != '\0'; iCounter++)
                {
                    this->push(sConcatination[iCounter]);
                }
            }
            void operator+=(string sConcatination)
            {
                int iLength = sConcatination.length();
                for (int iCounter = 0; iCounter < iLength; iCounter++)
                {
                    this->push(sConcatination[iCounter]);
                }
            }
            void operator+=(tType tConcatination)
            {
                this->push(tConcatination);
            }
            void operator+=(std::initializer_list<tType> ilConverting)
            {
                for(auto& tItem : ilConverting)
                {
                    this->push(tItem);
                }
            }
            /**
             * Removes element from List
             *
             * Argument is ListUnit
             */
            void operator-=(ListUnit<tType>* luConcatination)
            {
                this->remove(luConcatination);
            }
    };

#endif
