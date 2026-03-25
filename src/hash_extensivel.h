#ifndef HASH_EXTENSIVEL_H
#define HASH_EXTENSIVEL_H

#include <stdio.h>
#include <stdbool.h>

typedef struct HashExtensivel HashExtensivel;

/* Cria um novo hash table em disco e retorna o handle */
HashExtensivel* hash_criar(const char *caminho);

/* Abre um hash table existente em disco e retorna o handle */
HashExtensivel* hash_abrir(const char *caminho);

/* Fecha e libera o handle */
void hash_fechar(HashExtensivel *h);

/* Insere um par (chave, registro, sizeof(registro)). Retorna 0 em sucesso, -1 em erro */
int hash_inserir(HashExtensivel *h, const char *chave, const void* registro, size_t size_registro);

/* Busca o valor da chave e copia em saida. Retorna 0 se encontrou, -1 se não */
int hash_buscar(HashExtensivel *h, const char *chave, void* saida);

/* Remove o registro com a chave. Retorna 0 em sucesso, -1 se não encontrou */
int hash_remover(HashExtensivel *h, const char *chave);

/* Retorna true se a chave existe, false caso contrário */
bool hash_contem(HashExtensivel *h, const char *chave);

#endif