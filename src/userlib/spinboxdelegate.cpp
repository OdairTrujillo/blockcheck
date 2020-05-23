/*
    spinboxdelegate.cpp

    A delegate that allows the user to change integer values from the model
    using a spin box widget.
*/

#include <QtWidgets>
#include <QSqlQuery>

#include "spinboxdelegate.h"

SpinBoxDelegate::SpinBoxDelegate(const QString type, QObject *parent)
    : QItemDelegate(parent)
{
    Type=type;
}

QWidget *SpinBoxDelegate::createEditor(QWidget *parent,
    const QStyleOptionViewItem &/* option */,
    const QModelIndex &/* index */) const
{
    if (Type=="money") {
    QSpinBox *editor = new QSpinBox(parent);
    editor->setMinimum(0);
    editor->setMaximum(1000000000);
    editor->setPrefix("$");
    editor->setButtonSymbols(QSpinBox::NoButtons);
    return editor;
    }

    if (Type=="ohms") {
        QDoubleSpinBox *editor = new QDoubleSpinBox(parent);
        editor->setMinimum(0.00);
        editor->setMaximum(10000.00);
        editor->setDecimals(2);
        editor->setSingleStep(0.5);
        editor->setSuffix(" Ohms");
        return editor;
    }

    if (Type=="kva") {
        QDoubleSpinBox *editor = new QDoubleSpinBox(parent);
        editor->setMinimum(0.00);
        editor->setMaximum(10000000.00);
        editor->setDecimals(2);
        editor->setSingleStep(0.5);
        editor->setSuffix(" kVA");
        return editor;
    }
}

void SpinBoxDelegate::setEditorData(QWidget *editor,
                                    const QModelIndex &index) const
{
    // Pregunto si se creó el doublespinbox
    if (editor->metaObject()->className()==QString("QDoubleSpinBox")) {
        double value = index.model()->data(index, Qt::EditRole).toDouble();

        QDoubleSpinBox *spinBox = static_cast<QDoubleSpinBox*>(editor);
        spinBox->setValue(value);

    } else { // si es para moneda y entero
        int value = index.model()->data(index, Qt::EditRole).toInt();

        QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
        spinBox->setValue(value);
    }
}

void SpinBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                   const QModelIndex &index) const
{
    // hay que preguntar si es doublespinbox
    if (editor->metaObject()->className()==QString("QDoubleSpinBox")) {
        QDoubleSpinBox *spinBox = static_cast<QDoubleSpinBox*>(editor);
        spinBox->interpretText();
        double value = spinBox->value();
        model->setData(index, value, Qt::EditRole);

    } else { // si es para moneda y entero
        QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
        spinBox->interpretText();
        int value = spinBox->value();

        // Esto se hace para dar formato de moneda usando las capacidades de postgresql
        QSqlQuery formatValue;
        formatValue.prepare("SELECT :number::money");
        formatValue.bindValue(":number", value);
        formatValue.exec();
        formatValue.first();

        model->setData(index, formatValue.value(0).toString(), Qt::EditRole);
    }

}

void SpinBoxDelegate::updateEditorGeometry(QWidget *editor,
    const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{
    editor->setGeometry(option.rect);
}

