#include <QApplication>
#include "tilemapeditor.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    TileMapEditor editor;
    editor.show();

    return QApplication::exec();
}
