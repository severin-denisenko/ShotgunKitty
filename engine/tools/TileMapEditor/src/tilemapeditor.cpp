//
// Created by Severin on 04.03.2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_TileMapEditor.h" resolved

#include "tilemapeditor.h"
#include "ui_TileMapEditor.h"


TileMapEditor::TileMapEditor(QWidget* parent) :
        QMainWindow(parent), ui(new Ui::TileMapEditor) {
    ui->setupUi(this);

    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));

}

TileMapEditor::~TileMapEditor() {
    delete ui;
}
