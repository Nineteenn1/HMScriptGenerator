#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>

namespace Homemade
{
    class HMScriptGenerator
    {
    public:
        void GenerateNewScript();
        
    private:
        void CheckIfPathExists(const std::string& path);
        void InsertBaseScript(const std::string& baseScript);
        void ScriptSetup();
        
        std::string GetBaseScript() { return baseScript; }
        
        std::string FullNameSetup();
        std::string GetScriptNameInput();
        std::string GetPathInput();
        std::string GetFormatInput();
        // void LoadBaseScript(const std::string& path);
        // TODO: (?) Add a way to load the base script from a file
    private:
        std::ofstream output;
        std::string scriptName;
        std::string fullScriptName;
        // TODO: Handle big directories 
        std::string filePath;
        std::string fileFormat;
        
        std::string baseScript = 
            "function First()\n"
            "\n"
            "end\n"
            "\n"
            "function Update(deltaTime)\n"
            "\n"
            "end\n"
            "\n";
    };
}
