#include "generator.h"

namespace Homemade
{
    void LuaScriptGenerator::GenerateNewScript()
    {
        std::string scriptName = GetScriptNameInput();
        std::string filePath = GetPathInput();

        CheckIfPathExists(filePath);
        auto fullScriptName = FullNameSetup();
        ScriptSetup();
        output << GetBaseScript();
    }

    void LuaScriptGenerator::CheckIfPathExists(const std::string& path)
    {
        if (!std::filesystem::exists(path) || !std::filesystem::is_directory(path))
        {
            std::filesystem::create_directory(path);
        }
    }

    void LuaScriptGenerator::ScriptSetup()
    {
        output = static_cast<std::ofstream>(fullScriptName);
    }

    void LuaScriptGenerator::InsertBaseScript(const std::string& baseScript)
    {
        output << baseScript << std::endl;
    }

    std::string LuaScriptGenerator::GetPathInput()
    {
        std::cout << "\n" << "Enter the path of the script (always use slashes): ";
        std::cin >> filePath;            

        return filePath;
    }

    std::string LuaScriptGenerator::FullNameSetup()
    {
        fullScriptName = filePath + scriptName + ".lua";

        return fullScriptName;
    }

    std::string LuaScriptGenerator::GetScriptNameInput()
    {
        std::cout << "Enter the name of the script (without the extension): ";
        std::cin >> scriptName;

        return scriptName;
    }
}

// TODO: Handle multiple slashes within a path