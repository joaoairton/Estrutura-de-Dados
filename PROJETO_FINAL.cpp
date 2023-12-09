#include <iostream>
#include <queue>

using namespace std;

int main(){
    queue<int> fila1, fila2, filaP;  // armazena os clientes
    int caixa1 = 0, caixa2 = 0 , caixaP = 0;  // armazena os documentos dos clientes

    int pessoa_fisica_vazia = 0, pessoa_juridica_vazia = 0;
    int tam_max_fila1 = 0, tam_max_fila2 = 0;

    int n;  // quantidade de minutos
    cin >> n;

    for ( int i = 1; i <= n; i++ ) {

        int minuto, quantidade;
        char tipo;

        // Lê os valores de entrada em uma única linha
        cin >> minuto >> tipo >> quantidade;

        // Atualiza as filas e caixas
        if ( tipo == 'N' || tipo == 'n' ) {
            // Não chegou nenhum cliente neste minuto

        } else if ( tipo == 'F' || tipo == 'f' ) {
            if ( caixa1 == 0 && fila1.empty() ) {
                caixa1 = quantidade;  // recebe a qtd de documentos do cliente se a fila estiver vazia

            } else {
                fila1.push(quantidade);  // coloca o novo cliente com seus documentos no final da fila
            }

        } else if ( tipo == 'J' || tipo == 'j' ) {
            if ( caixa2 == 0 && fila2.empty() ) {
                caixa2 = quantidade;  // recebe a qtd de documentos do cliente se a fila estiver vazia

            }
            else {
                fila2.push(quantidade);  // coloca o novo cliente com seus documentos no final da fila
            }

        } else if ( tipo ==  'P' || tipo == 'p' ){
            if ( caixaP == 0 && filaP.empty() ){
                caixaP = quantidade;
            }
            else{
               filaP.push(quantidade);
            }
        }

        // Se a fila de pessoas físicas estiver vazia, incrementa o contador
        if ( fila1.empty() ) {
            pessoa_fisica_vazia++;
        }

        // Se a fila de pessoas jurídicas estiver vazia, incrementa o contador
        if ( fila2.empty() ) {
            pessoa_juridica_vazia++;
        }

        // Se a fila de pessoas físicas tiver um tamanho maior que o valor atual do contador, atualiza o contador
        if ( fila1.size() > tam_max_fila1 ) {
            tam_max_fila1 = fila1.size();
        }

        // Se a fila de pessoas juridicas tiver um tamanho maior que o valor atual do contador, atualiza o contador
        if ( fila2.size() > tam_max_fila2 ) {
            tam_max_fila2 = fila2.size();
        }

        cout << i << " ";  //  Imprime o minuto atual

        //  Atualiza a quantidade de documentos no caixa e remove o cliente da frente da fila.
        if ( caixa1 > 0 ) {
            cout << "A " << fila1.size() << " ";
            caixa1--;
            if ( caixa1 == 0 && !fila1.empty() ) {  //  testa se a qtd de docs é zero e se a fila está com algum cliente
                caixa1 = fila1.front();  //  retorna uma referência ao elemento da frente (o próximo a ser removido)
                fila1.pop();  //  remove o elemento da frente da fila.
            }

        } else {
            cout << "L " << fila1.size() << " ";  // indica que o caixa está livre
        }

        //  Atualiza a quantidade de documentos no caixa e remove o cliente da frente da fila.
        if ( caixa2 > 0 ) {
            cout << "A " << fila2.size() << " ";
            caixa2--;
            if ( caixa2 == 0 && !fila2.empty() ) {  //  testa se a qtd de docs é zero e se a fila está com algum cliente
                caixa2 = fila2.front();  //  retorna uma referência ao elemento da frente (o próximo a ser removido)
                fila2.pop();  //  remove o elemento da frente da fila.
            }

        } else {
            cout << "L " << fila2.size() << " ";  // indica que o caixa está livre
        }

         if ( caixaP > 0 ) {
            cout << "A " << filaP.size() << endl;
            caixaP--;
            if ( caixaP == 0 && !filaP.empty() ) {  //  testa se a qtd de docs é zero e se a fila está com algum cliente
                caixaP = filaP.front();  //  retorna uma referência ao elemento da frente (o próximo a ser removido)
                filaP.pop();  //  remove o elemento da frente da fila.
            }
        }else {
            cout << "L " << filaP.size() << endl;  // indica que o caixa está livre
        }
    }

    cout << "Qtd de vezes que a fila P_fisica ficou vazia: " << pessoa_fisica_vazia << endl;
    cout << "Maior tamanho da fila1 (P_fisica): " << tam_max_fila1 << endl;
    cout << "Qtd de vezes que a fila P_juridica ficou vazia: " << pessoa_juridica_vazia << endl;
    cout << "Maior tamanho da fila2 (P_juridica): " << tam_max_fila2 << endl;

    return 0;
}
