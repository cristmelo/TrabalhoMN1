typedef struct NodeResult_{
    double *result;
    NodeResult_ *next;
}NodeResult;



class ListResults{
    NodeResult *first;
    NodeResult *last;
    int lenght;
public:
    ListResults();
    ~ListResults();
    bool isEmpty();
    void push(double *result);
    double* pop();
    int getLength();
};
