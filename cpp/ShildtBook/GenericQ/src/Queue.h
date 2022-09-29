namespace QueueNamespace
{
    class QExcept 
    {
    public:
        char msg[80];
    };

    const int maxQsize = 100;

    template <class QType> class Queue 
    {
        QType q[maxQsize];
        int size;
        int putloc, getloc;
        QExcept QErr;

    public:

        Queue(int len)
        {
            if(len > maxQsize) len = maxQsize;
            else if(len <= 0) len = 1;

            size = len;
            putloc = getloc = 0;
        }

        void put(QType data)
        {
            if(putloc == size)
            {
                strcpy(QErr.msg, "Queue is full.\n");
                throw QErr;
            }

            putloc++;
            q[putloc] = data;
        }

        QType get()
        {
            if(getloc == putloc)
            {
               strcpy(QErr.msg, "Queue is empty.\n");
                throw QErr;
            }

            getloc++;
            return q[getloc];
        }
   }; 
}