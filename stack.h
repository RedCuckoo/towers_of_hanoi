using std::cout;
using std::cin;
using std::endl;

class staticStack {
private:
    int *stackBody;
    struct pointer{
        int *next;
    } *p;

public:
    staticStack (int maxSize);
    void add(int v);
    void pop ();
    int peek()const;
    void out()const;
};


