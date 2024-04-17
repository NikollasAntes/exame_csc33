#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Estrutura para representar um processo
typedef struct {
    int id; // Identificador do processo
    int burst_time; // Tempo de execução do processo
    int start_time; // Tempo de início da execução
    int end_time; // Tempo de conclusão da execução
} Process;

// Função para gerar um número aleatório entre min e max
int random_number(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    int num_processes;
    printf("Digite o número de processos: ");
    scanf("%d", &num_processes);

    // Aloca espaço para o array de processos
    Process *processes = malloc(num_processes * sizeof(Process));

    // Preenche informações dos processos
    for (int i = 0; i < num_processes; i++) {
        processes[i].id = i + 1;
        printf("Digite o tempo de execução do processo %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
    }

    // Simula o escalonamento aleatório
    int current_time = 0;
    for (int i = 0; i < num_processes; i++) {
        processes[i].start_time = current_time;
        int random_burst_time = random_number(1, processes[i].burst_time); // Tempo de execução aleatório
        processes[i].end_time = current_time + random_burst_time;
        current_time = processes[i].end_time;
    }

    // Calcula e exibe os tempos de cada processo
    printf("\nID\tBurst Time\tStart Time\tEnd Time\tTurnaround Time\tWaiting Time\tResponse Time\n");
    for (int i = 0; i < num_processes; i++) {
        int turnaround_time = processes[i].end_time - processes[i].start_time;
        int waiting_time = processes[i].start_time;
        int response_time = processes[i].start_time;

        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time,
               processes[i].start_time, processes[i].end_time, turnaround_time, waiting_time, response_time);
    }

    // Libera a memória alocada
    free(processes);

    return 0;
}
