#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>

namespace Homemade
{
    class LuaScriptGenerator
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

        
    private:
        std::ofstream output;
        std::string scriptName;
        std::string fullScriptName;
        std::string filePath;

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