//Stack using 2 queues

/* The method push to push element into the stack */
void QueueStack :: push(int x)
{
        // Your Code
        q1.push(x);
}

/*The method pop which return the element poped out of the stack*/
int QueueStack :: pop()
{
        // Your Code
        if(q1.empty())
            return -1;
        int n;
        while(!q1.empty()){
            n=q1.front();
            q1.pop();
            if(!q1.empty())
                q2.push(n);
        }
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }

        return n;
}
