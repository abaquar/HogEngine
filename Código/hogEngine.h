#define TAM_VIEWPORT_H       160
#define TAM_VIEWPORT_V       120

#define TAM_SPRITE           16   //Tamanho padrao do sprite: 8x8 pixels
#define MAX_SPRITES          128  //Número de sprites carregados na memória

#define TAM_VIEWPORT         TAM_VIEWPORT_H * TAM_VIEWPORT_V
#define TAM_SPRITE_QUADRADO  TAM_SPRITE * TAM_SPRITE
/****************/

typedef struct{
  char cor[TAM_SPRITE_QUADRADO];
} Sprite, *pSprite;

typedef struct{
  char dispositivo[TAM_VIEWPORT];  //Informacao de cada pixel mostrado atualmente no dispositivo
  char memoria[TAM_VIEWPORT];      //Informacao de cada pixel guardado na memoria da tela
} Viewport, *pViewport;

/****************/

Sprite spritesCarregados[MAX_SPRITES];
Viewport VIEWPORT;
char TRANSPARENTE;  //Cor de pixels nao desenhados nos sprites

/****************/

void hogInit(){
  ////////////////
  //Inicializa VGA
  ////////////////
  setup_pin_select();
  VGA.begin(VGAWISHBONESLOT(9),CHARMAPWISHBONESLOT(10));
  VGA.clear();
}

void desenhaTela(){
  ////////////////
  //Atualiza os pixels necessários no dispositivo para mostrar o que esta na memoria
  ////////////////
  for(int i=0; i<TAM_VIEWPORT; i++){
    if(VIEWPORT.dispositivo[i] != VIEWPORT.memoria[i]){
      VGA.setColor((int) VIEWPORT.memoria[i]);
      VGA.putPixel(i%TAM_VIEWPORT_H,i/TAM_VIEWPORT_H);
      VIEWPORT.dispositivo[i] = VIEWPORT.memoria[i];
    }
  }
}

void desenhaSprite(int idImagem, int x, int y){
  ////////////////
  //Desenha o sprite com o ID especificado nas coordenadas
  ////////////////
  int xTela = x;
  int yTela = y;
  int coluna, linha;
  for(int j=0; j<TAM_SPRITE; j++){
    for(int i=0; i<TAM_SPRITE; i++){
        coluna = xTela+i;
        linha  = yTela+j;
        if(coluna>=0 && coluna<TAM_VIEWPORT_H && linha>=0 && linha<TAM_VIEWPORT_V){
          if(spritesCarregados[idImagem].cor[i+(j*TAM_SPRITE)] != TRANSPARENTE){
            VIEWPORT.memoria[(xTela+i)+((yTela+j)*TAM_VIEWPORT_H)] = spritesCarregados[idImagem].cor[i+(j*TAM_SPRITE)];
          }
        }
    }
  }
}

void desenhaRect(char cor, int x, int y, int largura, int altura){
  for(int j=0; j<altura; j++){
    for(int i=0; i<largura; i++){
      VIEWPORT.memoria[(x+i) + (y+j)*TAM_VIEWPORT_H] = cor;
    }
  }
  
}

void loadImagem(int idDestino, char origem[]){
  ////////////////
  //Copia os pixelx contidos em um vetor para um sprite determinado na memoria
  ////////////////
  for(int i=0; i<TAM_SPRITE_QUADRADO; i++){
    spritesCarregados[idDestino].cor[i] = origem[i];
  }
}
