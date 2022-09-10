#include <sys/stat.h>
#include <iostream>
#include <QtCore>
#include <QtGui>
#include <filesystem>

#include "throughthedarklauncher.h"
#include "./ui_throughthedarklauncher.h"
#include "QMessageBox"

int forced = 0;

bool IsPathExist()
{
    std::string path;

#if linux
    path = "./ThroughTheDark-Archives/ThroughTheDark__nix";
#elif macos
    path = "./ThroughTheDark-Archives/osx";
#else
    path = "./ThroughTheDark-Archives/ThroughTheDark";
#endif

  struct stat buffer;
  return (stat (path.c_str(), &buffer) == 0);
}

ThroughTheDarkLauncher::ThroughTheDarkLauncher(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ThroughTheDarkLauncher)
{
    ui->setupUi(this);
}

ThroughTheDarkLauncher::~ThroughTheDarkLauncher()
{
    delete ui;
}

int isClicked = 0;

void ThroughTheDarkLauncher::on_pushButton_clicked()
{
    if(isClicked) return;
    isClicked = 1;
    if(IsPathExist() && forced == 0)
    {
        QMessageBox::information(this, "Update started", "Please wait for a bit for the launcher to update the game");
        #if linux
            system("cd ThroughTheDark-Archives && git fetch https://github.com/SomeBoringNerd/ThroughTheDark-Archives");
        #elif macos
            system("cd ThroughTheDark-Archives && git fetch https://github.com/SomeBoringNerd/ThroughTheDark-Archives");
        #else
            system("cd ThroughTheDark-Archives; git fetch https://github.com/SomeBoringNerd/ThroughTheDark-Archives");
        #endif
        QMessageBox::information(this, "Installation complete", "The game was updated successfully, you can now play");
    }else
    {
        #if linux
            system("rm -rf ./ThroughTheDark-Archives && git clone -b linux https://github.com/SomeBoringNerd/ThroughTheDark-Archives");
        #elif macos
            system("rm -rf ./ThroughTheDark-Archives && git clone -b osx https://github.com/SomeBoringNerd/ThroughTheDark-Archives");
        #else
            system("rmdir -r -f ThroughTheDark-Archives/; git clone https://github.com/SomeBoringNerd/ThroughTheDark-Archives");
        #endif

        QMessageBox::information(this, "Installation complete", "The game was downloaded successfully, you can now play");
    }
    isClicked = 0;
    std::cout << "Button was clicked" << std::endl;
}




void ThroughTheDarkLauncher::on_pushButton_2_clicked()
{
    if(IsPathExist())
    {
        std::cout << "Game exist" << std::endl;
        #if linux
            system("cd ThroughTheDark-Archives/ThroughTheDark__nix/ && ./TroughTheDark_nix.x86_64");
        #elif macos
            system("git fetch https://github.com/SomeBoringNerd/ThroughTheDark-Archives");
        #else
            system("cd ThroughTheDark-Archives/ThroughTheDark__nix; TroughTheDark.exe");
        #endif
    }else{
        std::cout << "Game dont exist" << std::endl;
        QMessageBox::information(this, "Error", "Game is not downloaded.");
    }
}





void ThroughTheDarkLauncher::on_checkBox_stateChanged(int arg1)
{
    forced = arg1;
    std::cout << arg1 << std::endl;
}

