//
// Created by Severin on 04.03.2023.
//

#ifndef SHOTGUNKITTY_TILEMAPEDITOR_H
#define SHOTGUNKITTY_TILEMAPEDITOR_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class TileMapEditor; }
QT_END_NAMESPACE

class TileMapEditor : public QMainWindow {
    Q_OBJECT

public:
    explicit TileMapEditor(QWidget* parent = nullptr);

    ~TileMapEditor() override;

private:
    Ui::TileMapEditor* ui;

    QImage tileMap;
};


#endif //SHOTGUNKITTY_TILEMAPEDITOR_H
