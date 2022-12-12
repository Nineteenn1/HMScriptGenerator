#include "HMScriptGenerator.h"

namespace Homemade
{
    void HMScriptGenerator::GenerateNewScript()
    {
        std::string scriptName = GetScriptNameInput();
        std::string filePath = GetPathInput();
        std::string fileFormat = GetFormatInput();

        CheckIfPathExists(filePath);
        auto fullScriptName = FullNameSetup();
        ScriptSetup();
        output << GetBaseScript();
    }

    void HMScriptGenerator::CheckIfPathExists(const std::string& path)
    {
        if (!std::filesystem::exists(path) || !std::filesystem::is_directory(path))
        {
            std::filesystem::create_directory(path);
        }
    }

    void HMScriptGenerator::ScriptSetup()
    {
        output = static_cast<std::ofstream>(fullScriptName);
    }

    void HMScriptGenerator::InsertBaseScript(const std::string& baseScript)
    {
        output << baseScript << std::endl;
    }

    std::string HMScriptGenerator::GetPathInput()
    {
        std::cout << "\n" << "Enter the path of the script (always use slashes): ";
        std::cin >> filePath;            

        return filePath;
    }

    std::string HMScriptGenerator::GetFormatInput()
    {
        std::cout << "\n" << "Enter the format of the script (E.g. .lua, .cpp): ";
        std::cin >> fileFormat;

        return fileFormat;
    }

    std::string HMScriptGenerator::FullNameSetup()
    {
        fullScriptName = filePath + scriptName + fileFormat;

        return fullScriptName;
    }

    std::string HMScriptGenerator::GetScriptNameInput()
    {
        std::cout << "Enter the name of the script (without the extension): ";
        std::cin >> scriptName;

        return scriptName;
    }
}

// TODO: Handle multiple slashes within a path