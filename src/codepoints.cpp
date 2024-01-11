#include <array>

struct CodepointEntry {
    const char* name = "";  // pointer to a statically allocated empty string
};

static std::array<CodepointEntry, 256> codepointNames;

static bool codepointNamesInitialized = false;

void initializeCodepointNames() {
    codepointNames[32] = CodepointEntry{ "SPACE" };
    codepointNames[33] = CodepointEntry{ "EXCLAMATION MARK" };
    codepointNames[34] = CodepointEntry{ "QUOTATION MARK" };
}

const char* getCodepointName(int codepoint) {
    if (!codepointNamesInitialized) {
        initializeCodepointNames();
    }
    if (codepoint < 32) {
        return "";
    }
    else if (codepoint > 255) {
        return "";
    }
    return codepointNames[codepoint].name;
}
