#ifndef GENERICTABLEDELEGATOR_H
#define GENERICTABLEDELEGATOR_H

#include <QStyledItemDelegate>

class GenericTableDelegator : public QStyledItemDelegate
{
public:
    GenericTableDelegator(QObject *parent = nullptr);
    /*!
     * \brief createEditor
     * Called by the view when a cell goes into edit mode
     * \param parent
     * \param option
     * \param index
     * \return 
     */
    QWidget *createEditor(QWidget *parent,
                          const QStyleOptionViewItem &option,
                          const QModelIndex &index) const override;
    /*!
     * \brief destroyEditor
     * Called by the view when editing is finished. Reimplemented to prevent
     * destroying of the editor
     * \param editor
     * \param index
     */
    void destroyEditor(QWidget *editor, const QModelIndex &index) const override;
    /*!
     * \brief setEditorData
     * Set the editor data.
     * Called when the model parameter changed or the editor was created
     * \param editor
     * \param index
     */
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    /*!
     * \brief setModelData
     * Set editor data to model
     * Called from the view when editing is finished and the editor content must be 
     * set in the model
     * \param editor
     * \param model
     * \param index
     */
    void setModelData(QWidget *editor,
                      QAbstractItemModel *model,
                      const QModelIndex &index) const override;
    void updateEditorGeometry(QWidget *editor,
                              const QStyleOptionViewItem &option,
                              const QModelIndex &index) const override;
};

#endif // GENERICTABLEDELEGATOR_H
