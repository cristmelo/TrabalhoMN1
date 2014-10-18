/**
*\file listResults.h
*\class ListResults
*\author Matheus Mayron
*\brief Uma lista com a função de armazenar a lihas do resultado gerado pelos métodos.
*/

/**
*\brief Uma linha do resultado
*/
typedef struct NodeResult_{
    double *result; ///<Aponta para um array onde devem estar armazenados dados relevantes sobre aquela iteração.
    NodeResult_ *next; ///<Aponta para um array onde devem estar armazenados os dados da iteração seguinte ou ser null. 
} NodeResult;



class ListResults{
    //!Aponta para o primeiro elemento da lista.
    NodeResult *first;
    //!Aponta o ultimo elemento da lista.
    NodeResult *last;
    //!Tamanho da lista.
    int lenght;
public:
    /**
    *   Controi um objeto do tipo ListResult. 
    *   Inicialmente first e last apontam para Null e leght é 0.
    */
    ListResults();

    /**
    *   Destroi o objeto.
    */
    ~ListResults();

    /**
    *   Verifica se a lista está vazia.
    *   \return Se estiver vazia retorna true, caso contrário retorna false.
    */
    bool isEmpty();

    /**
    *   Insere um nó no final da lista.
    *   \param result Um ponteiro para um array onde estão armazenados os dados relevantes a uma linha do resultado.
    */
    void push(double *result);

    /**
    *   Retira o primeiro elemento da lista.
    *   \return Um ponteiro apontado para os dados armazenados referentes a linha retirada.
    */
    double* pop();

    /**
    *   \return O tamanho da lista.
    */
    int getLength();
};
