begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|COMPLEXWIDGETS_H
end_ifndef
begin_define
DECL|macro|COMPLEXWIDGETS_H
define|#
directive|define
name|COMPLEXWIDGETS_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qpointer.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qaccessiblewidget.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qabstractitemview.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qaccessible2.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
DECL|variable|QAbstractButton
name|class
name|QAbstractButton
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QHeaderView
name|class
name|QHeaderView
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTabBar
name|class
name|QTabBar
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QComboBox
name|class
name|QComboBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTitleBar
name|class
name|QTitleBar
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractScrollArea
name|class
name|QAbstractScrollArea
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QScrollArea
name|class
name|QScrollArea
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SCROLLAREA
end_ifndef
begin_decl_stmt
name|class
name|QAccessibleAbstractScrollArea
range|:
name|public
name|QAccessibleWidget
block|{
name|public
operator|:
name|explicit
name|QAccessibleAbstractScrollArea
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;      enum
name|AbstractScrollAreaElement
block|{
name|Self
operator|=
literal|0
block|,
name|Viewport
block|,
name|HorizontalContainer
block|,
name|VerticalContainer
block|,
name|CornerWidget
block|,
name|Undefined
block|}
block|;
name|QAccessibleInterface
operator|*
name|child
argument_list|(
argument|int index
argument_list|)
specifier|const
block|;
name|QVariant
name|invokeMethod
argument_list|(
argument|QAccessible::Method method
argument_list|,
argument|int
argument_list|,
argument|const QVariantList&params
argument_list|)
block|;
name|int
name|childCount
argument_list|()
specifier|const
block|;
name|int
name|indexOfChild
argument_list|(
argument|const QAccessibleInterface *child
argument_list|)
specifier|const
block|;
name|bool
name|isValid
argument_list|()
specifier|const
block|;
name|int
name|navigate
argument_list|(
argument|RelationFlag relation
argument_list|,
argument|int entry
argument_list|,
argument|QAccessibleInterface **target
argument_list|)
specifier|const
block|;
comment|//    int childAt(int x, int y) const;
comment|//protected:
name|QAbstractScrollArea
operator|*
name|abstractScrollArea
argument_list|()
specifier|const
block|;
name|private
operator|:
name|QWidgetList
name|accessibleChildren
argument_list|()
specifier|const
block|;
name|AbstractScrollAreaElement
name|elementType
argument_list|(
argument|QWidget *widget
argument_list|)
specifier|const
block|;
name|bool
name|isLeftToRight
argument_list|()
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QAccessibleScrollArea
range|:
name|public
name|QAccessibleAbstractScrollArea
block|{
name|public
operator|:
name|explicit
name|QAccessibleScrollArea
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SCROLLAREA
end_comment
begin_if
if|#
directive|if
literal|0
end_if
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ITEMVIEWS
end_ifndef
begin_comment
unit|class QAccessibleHeader : public QAccessibleWidget { public:     explicit QAccessibleHeader(QWidget *w);      int childCount() const;      QRect rect(int child) const;     QString text(Text t, int child) const;     Role role(int child) const;     State state(int child) const;  protected:     QHeaderView *header() const; };  class QAccessibleItemRow: public QAccessibleInterface {     friend class QAccessibleItemView; public:     QAccessibleItemRow(QAbstractItemView *view, const QModelIndex&index = QModelIndex(), bool isHeader = false);     QRect rect(int child) const;     QString text(Text t, int child) const;     void setText(Text t, int child, const QString&text);     bool isValid() const;     QObject *object() const;     Role role(int child) const;     State state(int child) const;      int childCount() const;     int indexOfChild(const QAccessibleInterface *) const;     QList<QModelIndex> children() const;      Relation relationTo(int child, const QAccessibleInterface *other, int otherChild) const;     int childAt(int x, int y) const;     QAccessibleInterface *parent() const;     QAccessibleInterface *child(int index) const;     int navigate(RelationFlag relation, int index, QAccessibleInterface **iface) const;      int userActionCount(int child) const;     QString actionText(int action, Text t, int child) const;     bool doAction(int action, int child, const QVariantList&params = QVariantList());      QModelIndex childIndex(int child) const;      QHeaderView *horizontalHeader() const;
comment|//used by QAccessibleItemView
end_comment
begin_endif
unit|private:     static QAbstractItemView::CursorAction toCursorAction(Relation rel);     int logicalFromChild(QHeaderView *header, int child) const;     int treeLevel() const;     QHeaderView *verticalHeader() const;     QString text_helper(int child) const;      QPersistentModelIndex row;     QPointer<QAbstractItemView> view;     bool m_header; };  class QAccessibleItemView: public QAccessibleAbstractScrollArea, public QAccessibleTableInterface { public:     explicit QAccessibleItemView(QWidget *w);      QObject *object() const;     Role role(int child) const;     State state(int child) const;     QRect rect(int child) const;     int childAt(int x, int y) const;     int childCount() const;     QString text(Text t, int child) const;     void setText(Text t, int child, const QString&text);     int indexOfChild(const QAccessibleInterface *iface) const;      QModelIndex childIndex(int child) const;     int entryFromIndex(const QModelIndex&index) const;     bool isValid() const;     int navigate(RelationFlag relation, int index, QAccessibleInterface **iface) const;      QAccessibleInterface *accessibleAt(int row, int column);     QAccessibleInterface *caption();     int childIndex(int rowIndex, int columnIndex);     QString columnDescription(int column);     int columnSpan(int row, int column);     QAccessibleInterface *columnHeader();     int columnIndex(int childIndex);     int columnCount();     int rowCount();     int selectedColumnCount();     int selectedRowCount();     QString rowDescription(int row);     int rowSpan(int row, int column);     QAccessibleInterface *rowHeader();     int rowIndex(int childIndex);     int selectedRows(int maxRows, QList<int> *rows);     int selectedColumns(int maxColumns, QList<int> *columns);     QAccessibleInterface *summary();     bool isColumnSelected(int column);     bool isRowSelected(int row);     bool isSelected(int row, int column);     void selectRow(int row);     void selectColumn(int column);     void unselectRow(int row);     void unselectColumn(int column);     void cellAtIndex(int index, int *row, int *column, int *rowSpan,                      int *columnSpan, bool *isSelected);      QHeaderView *horizontalHeader() const;     QHeaderView *verticalHeader() const;     bool isValidChildRole(QAccessible::Role role) const;  protected:     QAbstractItemView *itemView() const;     QModelIndex index(int row, int column) const;  private:     inline bool atViewport() const {         return atVP;     };     QAccessible::Role expectedRoleOfChildren() const;      bool atVP; };
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TABBAR
end_ifndef
begin_decl_stmt
name|class
name|QAccessibleTabBar
range|:
name|public
name|QAccessibleWidget
block|{
name|public
operator|:
name|explicit
name|QAccessibleTabBar
argument_list|(
name|QWidget
operator|*
name|w
argument_list|)
block|;
name|int
name|childCount
argument_list|()
specifier|const
block|;
name|QString
name|text
argument_list|(
argument|Text t
argument_list|)
specifier|const
block|;
name|bool
name|setSelected
argument_list|(
argument|int child
argument_list|,
argument|bool on
argument_list|,
argument|bool extend
argument_list|)
block|;
name|QVector
operator|<
name|int
operator|>
name|selection
argument_list|()
specifier|const
block|;
name|QAccessibleInterface
operator|*
name|child
argument_list|(
argument|int index
argument_list|)
specifier|const
block|;
name|int
name|indexOfChild
argument_list|(
argument|const QAccessibleInterface *child
argument_list|)
specifier|const
block|;
name|int
name|navigate
argument_list|(
argument|RelationFlag rel
argument_list|,
argument|int entry
argument_list|,
argument|QAccessibleInterface **target
argument_list|)
specifier|const
block|;
name|protected
operator|:
name|QTabBar
operator|*
name|tabBar
argument_list|()
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_TABBAR
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_COMBOBOX
end_ifndef
begin_decl_stmt
name|class
name|QAccessibleComboBox
range|:
name|public
name|QAccessibleWidget
block|{
name|public
operator|:
name|explicit
name|QAccessibleComboBox
argument_list|(
name|QWidget
operator|*
name|w
argument_list|)
block|;
name|int
name|childCount
argument_list|()
specifier|const
block|;
name|int
name|childAt
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|)
specifier|const
block|;
name|int
name|indexOfChild
argument_list|(
argument|const QAccessibleInterface *child
argument_list|)
specifier|const
block|;
name|QAccessibleInterface
operator|*
name|child
argument_list|(
argument|int index
argument_list|)
specifier|const
block|;
name|QString
name|text
argument_list|(
argument|Text t
argument_list|)
specifier|const
block|;
comment|// QAccessibleActionInterface
name|QStringList
name|actionNames
argument_list|()
specifier|const
block|;
name|QString
name|localizedActionDescription
argument_list|(
argument|const QString&actionName
argument_list|)
specifier|const
block|;
name|void
name|doAction
argument_list|(
specifier|const
name|QString
operator|&
name|actionName
argument_list|)
block|;
name|QStringList
name|keyBindingsForAction
argument_list|(
argument|const QString&actionName
argument_list|)
specifier|const
block|;
name|protected
operator|:
name|QComboBox
operator|*
name|comboBox
argument_list|()
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_COMBOBOX
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_ACCESSIBILITY
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPLEXWIDGETS_H
end_comment
end_unit
