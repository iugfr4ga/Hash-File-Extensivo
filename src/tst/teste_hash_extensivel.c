#include "unity/unity.h"
#include "../hash_extensivel.h"

#define CAMINHO_TESTE "teste_hash"

static HashExtensivel *h = NULL;

void setUp(void) {
    h = hash_criar(CAMINHO_TESTE);
    TEST_ASSERT_NOT_NULL(h);
}

void tearDown(void) {
    hash_fechar(h);
    remove(CAMINHO_TESTE);
}

void test_criar(void) {
    TEST_ASSERT_NOT_NULL(h);
}

void test_inserir(void) {
    int v = 42;
    TEST_ASSERT_EQUAL_INT(0, hash_inserir(h, "chave", &v, sizeof(int)));
}

void test_buscar(void) {
    int v = 42, saida = 0;
    hash_inserir(h, "chave", &v, sizeof(int));
    TEST_ASSERT_EQUAL_INT(0, hash_buscar(h, "chave", &saida));
    TEST_ASSERT_EQUAL_INT(42, saida);
}

void test_remover(void) {
    int v = 42, saida = 0;
    hash_inserir(h, "chave", &v, sizeof(int));
    TEST_ASSERT_EQUAL_INT(0, hash_remover(h, "chave"));
    TEST_ASSERT_EQUAL_INT(-1, hash_buscar(h, "chave", &saida));
}

void test_contem(void) {
    int v = 1;
    hash_inserir(h, "chave", &v, sizeof(int));
    TEST_ASSERT_TRUE(hash_contem(h, "chave"));
    hash_remover(h, "chave");
    TEST_ASSERT_FALSE(hash_contem(h, "chave"));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_criar);
    RUN_TEST(test_inserir);
    RUN_TEST(test_buscar);
    RUN_TEST(test_remover);
    RUN_TEST(test_contem);
    return UNITY_END();
}