#include "FaseCaverna.h"
#include "Principal.h"
#include "Obstaculo.h"

namespace Fase {

    FaseCaverna::FaseCaverna(Principal *principal):
            Fase(), Estados::Estado(static_cast<Estados::MaquinaEstados*>(principal), Estados::IDestado::jogandoCaverna)
    {
        pEvento = Gerenciador::GerenciadorEvento::getGerenciadorEvento();
        pGrafico = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();
        ListaEntidadeEstatica = new Lista::ListaEntidade();
        ListaEntidadeMovimento = new Lista::ListaEntidade();
        pOriana = new Entidade::Personagem::Jogador::Oriana(Matematica::CoordenadaF(200.0f, 200.0f));
        pColisao = new Gerenciador::GerenciadorColisao(ListaEntidadeEstatica, ListaEntidadeMovimento);
        fundo = new Fundo(Ids::Ids::fase_caverna);
    }

    FaseCaverna::~FaseCaverna() { }

    void FaseCaverna::init() {

        if (iniciou) {
            return;
        }
        iniciou = true;
        //teste...
        if (doisJogadores) {
            pEvento->setJogadores(pOriana, pHideo);
        } else {
            if (pHideo)
                delete pHideo;
            pHideo = nullptr;
            pEvento->setJogadores(pOriana, nullptr);
        }

        ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade::Entidade*>(pOriana));
        if (doisJogadores) {
            ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade::Entidade *>(pHideo));
        }

        //arrumar ineficiente...
        //Matematica::CoordenadaF tam(100.0f, 30.0f);


        srand(time(NULL));
        for (int i = 0; i < 10; i++) {
            if (i != 6 && i != 7) {
                Matematica::CoordenadaF pos(i * 100.0f, 350.0f);
                Entidade::Obstaculo::Plataforma* plataforma = new Entidade::Obstaculo::Plataforma(pos);
                ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(plataforma));
            }
        }

        for (int i = 0; i < 2; i++) {
            Matematica::CoordenadaF pos2(200.f * (i + 1), 220.f);
            Entidade::Obstaculo::Plataforma* plataforma2 = new Entidade::Obstaculo::Plataforma(pos2);
            ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(plataforma2));
        }

        Matematica::CoordenadaF pos3(500.f, 100.f);
        Entidade::Obstaculo::Plataforma* plataforma3 = new Entidade::Obstaculo::Plataforma(pos3);
        ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(plataforma3));

        Matematica::CoordenadaF pos4(700.f, 100.f);
        Entidade::Obstaculo::Plataforma* plataforma5 = new Entidade::Obstaculo::Plataforma(pos4);
        ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(plataforma5));


        for (int i = 0; i < 10; i++) {
            Matematica::CoordenadaF pos5(100.0f * i, 600.f);
            Entidade::Obstaculo::Plataforma* plataforma6 = new Entidade::Obstaculo::Plataforma(pos5);
            ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(plataforma6));
        }

        Matematica::CoordenadaF pos5(-150.f, 480.f);
        Entidade::Obstaculo::Plataforma* plataforma7 = new Entidade::Obstaculo::Plataforma(pos5);
        ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(plataforma7));

        Entidade::Obstaculo::Espinhos* pAux = new Entidade::Obstaculo::Espinhos(Matematica::CoordenadaF(200.0f, 330.0f));
        ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(pAux));

        Entidade::Obstaculo::Pedra* pPedra = new Entidade::Obstaculo::Pedra(Matematica::CoordenadaF(100.0f, 600.0f - 50.0f));
        ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(pPedra));

        for (int i = 10; i < 20; i++) {
            Entidade::Obstaculo::Plataforma* plat = new Entidade::Obstaculo::Plataforma(Matematica::CoordenadaF((8 * 100.f) + 500.0f + ((i - 10) * 100.0f), 350.0f));
            ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(plat));
        }

        Entidade::Obstaculo::Pedra* pP = new Entidade::Obstaculo::Pedra(Matematica::CoordenadaF((8 * 100.f) + 500.0f + 8 * 105.0f + 50.0f, 350.0f - 50.0f));
        ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(pP));

        Entidade::Obstaculo::Pedra* pP2 = new Entidade::Obstaculo::Pedra(Matematica::CoordenadaF((8 * 100.f) + 500.0f, 350.0f - 50.0f));
        ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(pP2));

        Entidade::Obstaculo::Caixa* pCaixa = new Entidade::Obstaculo::Caixa(Matematica::CoordenadaF(200.0f - 100.0f, 350.0f - 50.0f));
        ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(pCaixa));
        Entidade::Obstaculo::Caixa* pCaixa2 = new Entidade::Obstaculo::Caixa(Matematica::CoordenadaF(200.0f - 150.0f, 350.0f - 50.0f));
        ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(pCaixa2));
        Entidade::Obstaculo::Caixa* pCaixa3 = new Entidade::Obstaculo::Caixa(Matematica::CoordenadaF(200.0f - 150.0f, 350.0f - 100.0f));
        ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(pCaixa3));

        Entidade::Obstaculo::Plataforma* platafor = new Entidade::Obstaculo::Plataforma(Matematica::CoordenadaF((6 * 100.f) + 500.0f, 250.0f));
        ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(platafor));

        for (int i = 0; i < 1; i++) {
            Entidade::Personagem::Inimigo::AtiraGoblin* pAtiraGoblin = new Entidade::Personagem::Inimigo::AtiraGoblin(Matematica::CoordenadaF((float)(rand()%1000), 100.f), pOriana, pHideo, ListaEntidadeMovimento);
            ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade::Entidade*>(pAtiraGoblin));
        }


        for (int i = 0; i < 1; i++) {
            Entidade::Personagem::Inimigo::AtiraEsqueleto* pAtiraEsqueleto = new Entidade::Personagem::Inimigo::AtiraEsqueleto(Matematica::CoordenadaF((float)(rand() % 1000), 100.f), pOriana, pHideo, ListaEntidadeMovimento);
            ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade::Entidade*>(pAtiraEsqueleto));
        }

        for (int i = 0; i < 2; i++) {
            Entidade::Personagem::Inimigo::BateGoblin* pBateGoblin = new Entidade::Personagem::Inimigo::BateGoblin(Matematica::CoordenadaF((float)(rand()%1000), 100.0f), pOriana, pHideo);
            ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade::Entidade*>(pBateGoblin));
        }

        for (int i = 0; i < 2; i++) {
            Entidade::Personagem::Inimigo::BateEsqueleto* pBateEsqueleto = new Entidade::Personagem::Inimigo::BateEsqueleto(Matematica::CoordenadaF((float)(rand()%1000), 100.f), pOriana, pHideo);
            ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade::Entidade*>(pBateEsqueleto));
        }

        for (int i = 0; i < 1; i++) {
            Entidade::Personagem::Inimigo::Animagus* pAnimagus = new Entidade::Personagem::Inimigo::Animagus(Matematica::CoordenadaF((float)(rand() % 1000) + 10 * 100.0f, 100.f), pOriana, pHideo);
            ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade::Entidade*>(pAnimagus));
        }

        Entidade::Personagem::Inimigo::Noturno* noturno = new Entidade::Personagem::Inimigo::Noturno(Matematica::CoordenadaF((float)(rand() % 1000) + 10 * 100.0f, 100.f), pOriana, pHideo);
        ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade::Entidade*>(noturno));



        Entidade::Obstaculo::Ponte* ponte2 = new Entidade::Obstaculo::Ponte(Matematica::CoordenadaF(900.0f, 600.0f - 50.0f * 6), 1);
        ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(ponte2));

        Entidade::Obstaculo::Espinhos* esp = new Entidade::Obstaculo::Espinhos(Matematica::CoordenadaF(650.0f, 600.0f - 50 * 5 - 30.0f - 20.0f));
        ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(esp));

    }
    void FaseCaverna::executar() { }

    void FaseCaverna::atualizar(const float tempo) {
        Matematica::CoordenadaF pos;
        if (pOriana->getPosicao().y < 315.f) {
            pos.operator=(Matematica::CoordenadaF(pOriana->getPosicao().x, pOriana->getPosicao().y));
        }
        else {
            pos.operator=(Matematica::CoordenadaF(pOriana->getPosicao().x, 315.0f));
        }
        fundo->atualizar(pos);
        pGrafico->centralizarCamera(pos);

        for (int i = 0; i < (int)ListaEntidadeEstatica->getTamanho(); i++) {
            Entidade::Obstaculo::Obstaculo* aux = static_cast<Entidade::Obstaculo::Obstaculo*>(ListaEntidadeEstatica->operator[](i));
            aux->atualizar(tempo);
        }
        //float tempo = pGrafico->atualizartempo();
        int i = 0;
        int tam = (int)ListaEntidadeMovimento->getTamanho();
        while (i < tam) {
            Entidade::Entidade* pEnt = ListaEntidadeMovimento->operator[](i);
            if (pEnt != nullptr) {
                pEnt->atualizar(tempo);
                if (pEnt->podeRemover()) {
                    ListaEntidadeMovimento->removerEntidade(pEnt);
                    //delete(pEnt);
                    //pEnt = nullptr;
                    tam = (int)ListaEntidadeMovimento->getTamanho();
                }
            }
            i++;
        }
        pColisao->Colisao();
    }

    void FaseCaverna::renderizar() {

    }

    void FaseCaverna::resetEstado() {
        //TODO: remover todas as entidades e resetar tudo antes de possivelmente reinicar a fase.
        init();
        pEvento->setJogadores(pOriana, pHideo);
    }
} //namespace Fase