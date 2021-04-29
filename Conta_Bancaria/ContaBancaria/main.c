#include <stdio.h>
#include <stdlib.h>
struct Cliente
{
    char nome[256];
    int cpf;
};

struct Cliente cliente;

struct Conta
{
    int    numero_da_conta;
    struct Cliente cliente;
    float  saldo;
};

struct Conta conta;

void menu();
void cadastrarCliente();
void criarconta();
void checarSaldo();
void depositar();
void sacar();
void extrato();

int main()
{
    printf("Bom dia! \n");
    menu();
    return 0;
}

void menu()
{
    int opcao;
    printf(" 1 - Cadastrar Cliente. \n");
    printf(" 2 - Criar Conta. \n");
    printf(" 3 - Checar Saldo. \n");
    printf(" 4 - Fazer Deposito. \n");
    printf(" 5 - Fazer Saque. \n");
    printf(" 6 - Extrato. \n");
    printf(" 7 - Sair. \n");
    printf("Selecione a operacao desejada: ");
    scanf("%d",&opcao);

    switch(opcao)
    {
        case 1:
        cadastrarCliente();
        break;
        case 2:
        criarconta();
        break;
        case 3:
        checarSaldo();
        break;
        case 4:
        depositar();
        break;
        case 5:
        sacar();
        break;
        case 6:
        extrato();
        break;
        case 7:
            printf(" Obrigado pela preferencia. \n");
        break;
        default:
            printf(" Escolha uma opção valida! \n");
            menu();
        break;
        }
    }


void cadastrarCliente() //funcao cadastra cliente
{
    printf("Digite seu CPF: \n");
    scanf("%d", &cliente.cpf);
    fflush(stdin);
    printf("Insira seu nome completo: \n");
    fgets(cliente.nome,256,stdin); //para digiar o nome do cliente
    printf("Cadastro realizado com sucesso! \n");
    printf("%s", cliente.nome);
    printf("%d", cliente.cpf);
    _sleep(3000);
    system ("cls");
    menu();
}

void criarconta() //funcao para criar uma conta
{
    int cpfcheck;
    int i = 100;
    printf("insira o CPF do dono da conta: ");
    scanf("%d",&cpfcheck);
    if(cpfcheck == cliente.cpf) //testa o cpf do cliente
    {
        conta.numero_da_conta = i + 1; // gera o numero da conta
        conta.saldo = 0; // conta começa com valor de saldo 0
        printf("Conta criada com sucesso \n");
        printf("Responsavel pela conta: %s \n", cliente.nome); // mostra o nome do cliente
        printf("CPF: %d \n", cliente.cpf); //mostra o cpf do cliente
        printf("Numero da conta: %d \n", conta.numero_da_conta);
        printf("    Saldo Atual: R$ %.2f \n", conta.saldo); //mostra o saldo atual da conta
    }
    else
    {
        printf("Cliente não cadastrado! \n");
    }
    _sleep(5000);
    system ("cls");
    menu();
}

void checarSaldo() //funcao saldo, mostrara o saldo da conta
{
    int ncontateste;
    int cpfteste;
    printf("digite o numero da conta: \n");
    scanf("%d",&ncontateste);
    if(ncontateste == conta.numero_da_conta) //testa o numero da conta
    {
        printf("digite o CPF do responsavel: \n");
        scanf("%d",&cpfteste);
        if(cpfteste == cliente.cpf) // testa o cpf
        {
            printf("Conta %d: \n", conta.numero_da_conta);
            printf("    Saldo Atual: R$ %.2f \n", conta.saldo); //mostra o saldo atual da conta
        }
        else
        {
            printf("CPF invalido! \n");
        }
    }
    else
    {
        printf("Conta não existente! \n");
    }
    _sleep(5000);
    system ("cls");
    menu();
}

void depositar() //funcao para realizar o deposito
{

    int ncontateste;
    int cpfteste;
    float deposito;
    printf("digite o numero da conta: \n");
    scanf("%d",&ncontateste);
    if(ncontateste == conta.numero_da_conta) //testa o numero da conta para ver se é vdd
    {
        printf("digite o CPF do responsavel: \n");
        scanf("%d",&cpfteste);
        if(cpfteste == cliente.cpf)// testa o cpf
        {
            printf("Quanto deseja depositar? \n");
            scanf("%f", &deposito);
            conta.saldo = conta.saldo + deposito; //soma o saldo atual com o valor do deposito
            printf("Deposito realizado com sucesso! \n");
            printf("    Novo saldo: R$ %.2f", conta.saldo); //mostra o novo saldo da conta
            FILE * pont_arq;
            pont_arq = fopen("resultado.txt", "a"); //cria um arquivo txt
            fprintf(pont_arq, "Deposito no valor de R$ %.2f\n       Saldo de R$ %.2f\n", deposito, conta.saldo);//salvo o valor do deposito e o novo saldo no arquivo txt
            fclose(pont_arq); //fecha o arquivo
    }

        else
        {
            printf("CPF invalido! \n");
        }
    }
    else
    {
        printf("Conta nao existente! \n");
    }
    _sleep(5000);
    system ("cls");
    menu();
}

void sacar() //funcao sacar, onde a pessoa vai ter acesso aos saques na conta dela
{
    int ncontateste, cpfteste;
    float valorS;
    printf("digite o numero da conta: \n");
    scanf("%d",&ncontateste);
    if(ncontateste == conta.numero_da_conta) //testa os dados da conta para ver se é igual, se for liberara a fucao saque
    {
        printf("digite o CPF do responsavel: \n");
        scanf("%d",&cpfteste);
        if(cpfteste == cliente.cpf) //mesma coisa, testa o cpf para ver se é igual
        {
            if(conta.saldo <= 0) // se o saldo da conta for igual a 0 não libera o saque retorna para o menu
            {
                printf("Sem saldo na conta, Nao eh Possivel realizar o Saque\n");
                _sleep(3000);
                system("cls");
                menu();
            }
            printf("Digite a quantidade que deseja Sacar: \n");
            scanf("%f", &valorS);
            if(valorS > conta.saldo) // se o valor pedido for maior q o saldo, não permitira o saque e voltara para o menu
            {
                printf("Saldo Insuficiente\n");
            }
            else
            {
                printf("Saque realizado no Valor de R$ %2.f\n", valorS); // saque realizado com sucesso
                conta.saldo = conta.saldo - valorS; //conta para o novo saldo
                printf("    Novo saldo R$ %.2f\n\n", conta.saldo); // mostra o saldo da conta depois do saque
                FILE * pont_arq;
                pont_arq = fopen("resultado.txt", "a"); //cria um arquivo de teste
                fprintf(pont_arq, "Saque no Valor de R$ %.2f \n     Saldo de R$ %.2f\n", valorS, conta.saldo); // salva as informacoes a operação realizada no arquivo de testo criado
                fclose(pont_arq); //fecha o arquivo
            }
        }
        else
        {
            printf("CPF invalido! \n");
        }
    }
    else
    {
        printf("Conta não existente! \n");
    }
    _sleep(5000);
    system ("cls");
    menu();
}
void extrato(){ //funcao extrato, mostra todas as transacoes realizada
    char ch;
    FILE *pont_arq = fopen("resultado.txt", "r"); //abre o arquivo txt em q foi salvo as transacoes
    while((ch=fgetc(pont_arq))!=EOF){ //le os dados do arquivo
        putchar(ch); //printa os dados do arquivo na tela
}
fclose(pont_arq);
_sleep(5000);
system("cls");
menu();
}
