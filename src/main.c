#include <kernel.h>
#include <sys/printk.h>


#define STACK_SIZE 1024
#define THREAD_PRIORITY 1


/* RECURSO COMPARTILHADO (Estoque de Produtos) */
static volatile int saldo_vitrine = 0;


/* =========================================================================
 * THREAD 1: Produção do Padeiro
 * ========================================================================= */
void thread_padeiro(void *p1, void *p2, void *p3)
{
   while(1) {
    k_msleep(100);
    saldo_vitrine++;

    printk("Padeiro adicionou 1 pao. Saldo da vitrine: %d\n", saldo_vitrine);

   }
}

/* =========================================================================
 * THREAD 2: Consumo dos pães pelos Clientes
 * ========================================================================= */
void thread_clientes(void *p1, void *p2, void *p3)
{
   while (1) {
    k_msleep(150);

    saldo_vitrine--;

   printk("Cliente comprou 1 pao. Saldo da vitrine: %d\n", saldo_vitrine);

 
   }
}



/* Definição das Threads */
K_THREAD_DEFINE(t_reposicao, STACK_SIZE, thread_padeiro, NULL, NULL, NULL, 1, 0, 0);
K_THREAD_DEFINE(t_vendas, STACK_SIZE, thread_clientes, NULL, NULL, NULL, 1, 0, 0);

int main(void)
{
    while (1)
    {
     k_msleep(10000000);
    }
    
}
