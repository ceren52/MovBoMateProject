#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Öneri butonuna tıklama olayını bağlama
    connect(ui->suggestButton, &QPushButton::clicked, this, &MainWindow::onSuggestButtonClicked);

    // Örnek ruh hali seçeneklerini doldurma
    ui->moodComboBox->addItems({"Mutlu", "Hüzünlü", "Heyecanlı", "Sakin", "Nostalgik"});
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onSuggestButtonClicked()
{
    QString mood = ui->moodComboBox->currentText();
    QString suggestion;

    if (ui->kitapRadioButton->isChecked()) {
        suggestion = getBookSuggestion(mood);
    } else if (ui->filmRadioButton->isChecked()) {
        suggestion = getMovieSuggestion(mood);
    } else {
        QMessageBox::warning(this, "Hata", "Lütfen kitap veya film seçiniz.");
        return;
    }

    ui->suggestionLabel->setText(suggestion);
}

QString MainWindow::getBookSuggestion(const QString& mood)
{
    // Basit öneriler (daha sonra gerçek veri veya algoritma ile değiştirilir)
    if (mood == "Mutlu") return "Mutlu Kitap 1";
    if (mood == "Hüzünlü") return "Hüzünlü Kitap 1";
    if (mood == "Heyecanlı") return "Heyecanlı Kitap 1";
    if (mood == "Sakin") return "Sakin Kitap 1";
    if (mood == "Nostalgik") return "Nostalgik Kitap 1";
    return "Kitap önerisi bulunamadı.";
}

QString MainWindow::getMovieSuggestion(const QString& mood)
{
    // Basit öneriler (daha sonra gerçek veri veya algoritma ile değiştirilir)
    if (mood == "Mutlu") return "Mutlu Film 1";
    if (mood == "Hüzünlü") return "Hüzünlü Film 1";
    if (mood == "Heyecanlı") return "Heyecanlı Film 1";
    if (mood == "Sakin") return "Sakin Film 1";
    if (mood == "Nostalgik") return "Nostalgik Film 1";
    return "Film önerisi bulunamadı.";
}
