//------------------------------------------------------------------------------
// Copyright 2025 Andre Kishimoto
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Exemplo: 04-invert_image
// O programa carrega o arquivo de imagem indicado na constante IMAGE_FILENAME
// e exibe o conteúdo na janela ("kodim23.png" pertence ao Kodak Image Set).
// A tecla '1' aplica a transformação de intensidade (negativo da imagem).
// Caso a imagem seja maior do que WINDOW_WIDTHxWINDOW_HEIGHT, a janela é
// redimensionada logo após a imagem ser carregada.
//
// Observação:
// Em um projeto mais realista, o código abaixo provavelmente seria refatorado.
// Por exemplo, as funções loadRGBA32() e invertImage() seriam divididas em
// funções menores e com responsabilidades específicas, além de não dependerem
// de variáveis globais (vide princípios SOLID).
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>

//------------------------------------------------------------------------------
// Constants and enums
//------------------------------------------------------------------------------
static const char *WINDOW_TITLE = "Invert image";
static const char *IMAGE_FILENAME = "kodim23.png";

enum constants
{
  WINDOW_WIDTH = 640,
  WINDOW_HEIGHT = 480,
};

//------------------------------------------------------------------------------
// Globals
//------------------------------------------------------------------------------
static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;
static SDL_Surface *surface = NULL;
static SDL_Texture *texture = NULL;
static SDL_FRect textureRect = { .x = 0.0f, .y = 0.0f, .w = 0.0f, .h = 0.0f };

//------------------------------------------------------------------------------
// Function declaration
//------------------------------------------------------------------------------

/**
 * Carrega a imagem indicada no parâmetro `filename` e a converte para o formato
 * RGBA32, eliminando dependência do formato original da imagem.
 */
static void loadRGBA32(const char *filename);

/**
 * Acessa cada pixel da imagem (surface) e inverte sua intensidade.
 * Altera a global surface e atualiza a global texture.
 * 
 * Assumimos que os pixels da imagem estão no formato RGBA32 e que os níveis de
 * intensidade estão no intervalo [0-255].
 * 
 * Na verdade, podemos desconsiderar o canal Alpha, já que ele não terá seu
 * valor invertido. Neste caso, substituímos `SDL_GetRGBA()` e `SDL_MapRGBA()`
 * por `SDL_GetRGB()` e `SDL_MapRGB()`, respectivamente.
 */
static void invertImage(void);

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static SDL_AppResult initialize(void)
{
  SDL_Log("Iniciando SDL...\n");
  if (!SDL_Init(SDL_INIT_VIDEO))
  {
    SDL_Log("*** Erro ao iniciar a SDL: %s\n", SDL_GetError());
    return SDL_APP_FAILURE;
  }

  SDL_Log("Criando janela e renderizador...\n");
  if (!SDL_CreateWindowAndRenderer(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT, 0,
                                   &window, &renderer))
  {
    SDL_Log("Erro ao criar a janela e/ou renderizador: %s\n", SDL_GetError());
    return SDL_APP_FAILURE;
  }

  return SDL_APP_CONTINUE;
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void shutdown(void)
{
  SDL_Log("Destruindo textura...\n");
  SDL_DestroyTexture(texture);
  texture = NULL;

  SDL_Log("Destruindo superfície...\n");
  SDL_DestroySurface(surface);
  surface = NULL;

  SDL_Log("Destruindo renderizador...\n");
  SDL_DestroyRenderer(renderer);
  renderer = NULL;

  SDL_Log("Destruindo janela...\n");
  SDL_DestroyWindow(window);
  window = NULL;

  SDL_Log("Encerrando SDL...\n");
  SDL_Quit();
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void loop(void)
{
  SDL_Event event;
  bool isRunning = true;
  while (isRunning)
  {
    while (SDL_PollEvent(&event))
    {
      switch (event.type)
      {
      case SDL_EVENT_QUIT:
        isRunning = false;
        break;

      case SDL_EVENT_KEY_DOWN:
        if (event.key.key == SDLK_1 && !event.key.repeat)
        {
          invertImage();
        }
        break;
      }
    }

    SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);
    SDL_RenderClear(renderer);

    SDL_RenderTexture(renderer, texture, &textureRect, &textureRect);

    SDL_RenderPresent(renderer);
  }
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void loadRGBA32(const char *filename)
{
  SDL_Log("Carregando imagem '%s'...\n", filename);
  surface = IMG_Load(filename);
  if (!surface)
  {
    SDL_Log("*** Erro ao carregar a imagem: %s\n", SDL_GetError());
    return;
  }

  SDL_Log("Convertendo superfície para formato RGBA32...\n");
  SDL_Surface *converted = SDL_ConvertSurface(surface, SDL_PIXELFORMAT_RGBA32);
  SDL_DestroySurface(surface);
  if (!converted)
  {
    SDL_Log("*** Erro ao converter superfície para formato RGBA32: %s\n", SDL_GetError());
    surface = NULL;
    return;
  }

  surface = converted;

  SDL_Log("Criando textura a partir da superfície...\n");
  texture = SDL_CreateTextureFromSurface(renderer, surface);
  if (!texture)
  {
    SDL_Log("*** Erro ao criar textura: %s\n", SDL_GetError());
    return;
  }

  SDL_GetTextureSize(texture, &textureRect.w, &textureRect.h);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void invertImage(void)
{
  if (!surface)
  {
    SDL_Log("*** Erro em invertImage(): Imagem inválida!\n");
    return;
  }

  SDL_LockSurface(surface);

  const SDL_PixelFormatDetails *format = SDL_GetPixelFormatDetails(surface->format);
  const size_t pixelCount = surface->w * surface->h;

  Uint32 *pixels = (Uint32 *)surface->pixels;
  Uint8 r = 0;
  Uint8 g = 0;
  Uint8 b = 0;
  Uint8 a = 0;

  for (size_t i = 0; i < pixelCount; ++i)
  {
    SDL_GetRGBA(pixels[i], format, NULL, &r, &g, &b, &a);

    r = 255 - r;
    g = 255 - g;
    b = 255 - b;

    pixels[i] = SDL_MapRGBA(format, NULL, r, g, b, a);
  }

  SDL_UnlockSurface(surface);

  SDL_DestroyTexture(texture);
  texture = SDL_CreateTextureFromSurface(renderer, surface);
}

//------------------------------------------------------------------------------
// 
//------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
  atexit(shutdown);

  if (initialize() == SDL_APP_FAILURE)
    return SDL_APP_FAILURE;

  loadRGBA32(IMAGE_FILENAME);

  if (textureRect.w > WINDOW_WIDTH || textureRect.h > WINDOW_HEIGHT)
  {
    SDL_SetWindowSize(window, (int)textureRect.w, (int)textureRect.h);
    SDL_SyncWindow(window);
  }

  loop();

  return 0;
}
