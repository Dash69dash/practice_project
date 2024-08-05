#include <iostream>
#include <fstream>  
#include <filesystem>  
#include <string>  
#include <vector>  
#include <openxlsx.h> 

namespace fs = std::filesystem;

void processTextFile(const fs::path& filePath);

int main() {
    fs::path directoryPath = "E:\\VisualStudio2019Community\\��Ŀ����λ��\\processing_data\\input\\example"; // �滻Ϊ����ļ���·��  

    if (!fs::exists(directoryPath) || !fs::is_directory(directoryPath)) {
        std::cerr << "·�������ڻ���һ��Ŀ¼\n";
        return 1;
    }

    for (const auto& entry : fs::directory_iterator(directoryPath)) {
        if (entry.path().extension() == ".txt") {
            // �����ı��ļ�  
            processTextFile(entry.path());
        }
    }

    return 0;
}

void processTextFile(const fs::path& filePath) {
    std::ifstream fileStream(filePath);
    if (!fileStream.is_open()) {
        std::cerr << "�޷����ļ�: " << filePath << '\n';
        return;
    }

    std::string line;
    while (std::getline(fileStream, line)) {
        // ���������ÿһ�е�����  
        // ����: std::cout << line << '\n'; // ���ÿһ������  
        std::cout << "�ļ������ɹ�" << '\n';
    }

    // ����Excel�������͹�����  
    openxlsx::Workbook workbook;
    openxlsx::Worksheet worksheet(&workbook);
    worksheet.load_from_xml("your_excel_template.xlsx"); // ����Excelģ���ļ�  

    // ������д��Excel������  
    int rowIndex = 1; // �ӵڶ��п�ʼд������  
    for (const auto& row : data) {
        int columnIndex = 1; // �ӵ�һ�п�ʼд������  
        for (const auto& cell : row) {
            worksheet.set_cell_value(rowIndex, columnIndex, cell);
            columnIndex++;
        }
        rowIndex++;
    }

    // ����Excel�ļ�  
    workbook.save("output.xlsx");


    fileStream.close();
}