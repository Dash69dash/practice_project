#include <iostream>
#include <fstream>  
#include <filesystem>  
#include <string>  
#include <vector>  
#include <openxlsx.h> 

namespace fs = std::filesystem;

void processTextFile(const fs::path& filePath);

int main() {
    fs::path directoryPath = "E:\\VisualStudio2019Community\\项目保存位置\\processing_data\\input\\example"; // 替换为你的文件夹路径  

    if (!fs::exists(directoryPath) || !fs::is_directory(directoryPath)) {
        std::cerr << "路径不存在或不是一个目录\n";
        return 1;
    }

    for (const auto& entry : fs::directory_iterator(directoryPath)) {
        if (entry.path().extension() == ".txt") {
            // 处理文本文件  
            processTextFile(entry.path());
        }
    }

    return 0;
}

void processTextFile(const fs::path& filePath) {
    std::ifstream fileStream(filePath);
    if (!fileStream.is_open()) {
        std::cerr << "无法打开文件: " << filePath << '\n';
        return;
    }

    std::string line;
    while (std::getline(fileStream, line)) {
        // 在这里解析每一行的数据  
        // 例如: std::cout << line << '\n'; // 输出每一行内容  
        std::cout << "文件解析成功" << '\n';
    }

    // 创建Excel工作簿和工作表  
    openxlsx::Workbook workbook;
    openxlsx::Worksheet worksheet(&workbook);
    worksheet.load_from_xml("your_excel_template.xlsx"); // 加载Excel模板文件  

    // 将数据写入Excel工作表  
    int rowIndex = 1; // 从第二行开始写入数据  
    for (const auto& row : data) {
        int columnIndex = 1; // 从第一列开始写入数据  
        for (const auto& cell : row) {
            worksheet.set_cell_value(rowIndex, columnIndex, cell);
            columnIndex++;
        }
        rowIndex++;
    }

    // 保存Excel文件  
    workbook.save("output.xlsx");


    fileStream.close();
}