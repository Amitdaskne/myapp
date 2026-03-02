#define STBI_NOTUSED(v)  (void)sizeof(v)
#define STB_IMAGE_IMPLEMENTATION
#include "imgui/stb_image.h"

#include "imgui/Image/EXTRA/LOOTBOX.h"
#include "imgui/Image/EXTRA/LOGO.h"

struct TextureInfo {
ImTextureID textureId;
int x;
int y;
int w;
int h;
};

static TextureInfo textureInfo;

TextureInfo createTexture(const unsigned char *buffer,int len) {
int w, h, n;
stbi_uc *data = stbi_load_from_memory(buffer,len, &w, &h, &n, 0);
GLuint texture;
glGenTextures(1, &texture);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
if (n == 3) {
glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
} else {
glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
}
stbi_image_free(data);
textureInfo.textureId = reinterpret_cast<ImTextureID>((GLuint *) texture);
textureInfo.w = w;
textureInfo.h = h;
return textureInfo;
}


extern TextureInfo LOOTBOX;
TextureInfo LOOTBOX;
extern TextureInfo LOGO;
TextureInfo LOGO;



void DrawImage(int x, int y, int w, int h, ImTextureID Texture);
void DrawImage(int x, int y, int w, int h, ImTextureID Texture) {
ImGui::GetForegroundDrawList()->AddImage(Texture, ImVec2(x, y), ImVec2(x + w, y + h));
}

void InitTexture() {
LOOTBOX = createTexture(LootBox_data, sizeof(LootBox_data));
LOGO = createTexture(LOGO_data, sizeof(LOGO_data));
}

void InitTexture();
