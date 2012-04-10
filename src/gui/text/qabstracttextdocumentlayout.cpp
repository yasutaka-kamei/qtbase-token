begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qabstracttextdocumentlayout.h>
end_include
begin_include
include|#
directive|include
file|<qtextformat.h>
end_include
begin_include
include|#
directive|include
file|"qtextdocument_p.h"
end_include
begin_include
include|#
directive|include
file|"qtextengine_p.h"
end_include
begin_include
include|#
directive|include
file|"qabstracttextdocumentlayout_p.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QAbstractTextDocumentLayout     \reentrant      \brief The QAbstractTextDocumentLayout class is an abstract base     class used to implement custom layouts for QTextDocuments.      \ingroup richtext-processing      The standard layout provided by Qt can handle simple word processing     including inline images, lists and tables.      Some applications, e.g., a word processor or a DTP application might need     more features than the ones provided by Qt's layout engine, in which case     you can subclass QAbstractTextDocumentLayout to provide custom layout     behavior for your text documents.      An instance of the QAbstractTextDocumentLayout subclass can be installed     on a QTextDocument object with the     \l{QTextDocument::}{setDocumentLayout()} function.      You can insert custom objects into a QTextDocument; see the     QTextObjectInterface class description for details.      \sa QTextObjectInterface */
end_comment
begin_comment
comment|/*!     \class QTextObjectInterface     \brief The QTextObjectInterface class allows drawing of            custom text objects in \l{QTextDocument}s.     \since 4.5      A text object describes the structure of one or more elements in a     text document; for instance, images imported from HTML are     implemented using text objects. A text object knows how to lay out     and draw its elements when a document is being rendered.      Qt allows custom text objects to be inserted into a document by     registering a custom \l{QTextCharFormat::objectType()}{object     type} with QTextCharFormat. A QTextObjectInterface must also be     implemented for this type and be     \l{QAbstractTextDocumentLayout::registerHandler()}{registered}     with the QAbstractTextDocumentLayout of the document. When the     object type is encountered while rendering a QTextDocument, the     intrinsicSize() and drawObject() functions of the interface are     called.      The following list explains the required steps of inserting a     custom text object into a document:      \list         \li Choose an \a objectType. The \a objectType is an integer with a             value greater or equal to QTextFormat::UserObject.          \li Create a QTextCharFormat object and set the object type to the             chosen type using the setObjectType() function.          \li Implement the QTextObjectInterface class.          \li Call QAbstractTextDocumentLayout::registerHandler() with an instance of your             QTextObjectInterface subclass to register your object type.          \li Insert QChar::ObjectReplacementCharacter with the aforementioned             QTextCharFormat of the chosen object type into the document.             As mentioned, the functions of QTextObjectInterface             \l{QTextObjectInterface::}{intrinsicSize()} and             \l{QTextObjectInterface::}{drawObject()} will then be called with the             QTextFormat as parameter whenever the replacement character is             encountered.     \endlist      A class implementing a text object needs to inherit both QObject     and QTextObjectInterface. QObject must be the first class     inherited. For instance:      \snippet examples/richtext/textobject/svgtextobject.h 1      The data of a text object is usually stored in the QTextCharFormat     using QTextCharFormat::setProperty(), and then retrieved with     QTextCharFormat::property().      \warning Copy and Paste operations ignore custom text objects.      \sa {Text Object Example}, QTextCharFormat, QTextLayout */
end_comment
begin_comment
comment|/*!     \fn QTextObjectInterface::~QTextObjectInterface()      Destroys this QTextObjectInterface. */
end_comment
begin_comment
comment|/*!     \fn virtual QSizeF QTextObjectInterface::intrinsicSize(QTextDocument *doc, int posInDocument, const QTextFormat&format) = 0      The intrinsicSize() function returns the size of the text object     represented by \a format in the given document (\a doc) at the     given position (\a posInDocument).      The size calculated will be used for subsequent calls to     drawObject() for this \a format.      \sa drawObject() */
end_comment
begin_comment
comment|/*!     \fn virtual void QTextObjectInterface::drawObject(QPainter *painter, const QRectF&rect, QTextDocument *doc, int posInDocument, const QTextFormat&format) = 0      Draws this text object using the specified \a painter.      The size of the rectangle, \a rect, to draw in is the size     previously calculated by intrinsicSize(). The rectangles position     is relative to the \a painter.      You also get the document (\a doc) and the position (\a     posInDocument) of the \a format in that document.      \sa intrinsicSize() */
end_comment
begin_comment
comment|/*!     \fn void QAbstractTextDocumentLayout::update(const QRectF&rect)      This signal is emitted when the rectangle \a rect has been updated.      Subclasses of QAbstractTextDocumentLayout should emit this signal when     the layout of the contents change in order to repaint. */
end_comment
begin_comment
comment|/*!    \fn void QAbstractTextDocumentLayout::updateBlock(const QTextBlock&block)    \since 4.4     This signal is emitted when the specified \a block has been updated.     Subclasses of QAbstractTextDocumentLayout should emit this signal when    the layout of \a block has changed in order to repaint.  */
end_comment
begin_comment
comment|/*!     \fn void QAbstractTextDocumentLayout::documentSizeChanged(const QSizeF&newSize)      This signal is emitted when the size of the document layout changes to     \a newSize.      Subclasses of QAbstractTextDocumentLayout should emit this signal when the     document's entire layout size changes. This signal is useful for widgets     that display text documents since it enables them to update their scroll     bars correctly.      \sa documentSize() */
end_comment
begin_comment
comment|/*!     \fn void QAbstractTextDocumentLayout::pageCountChanged(int newPages)      This signal is emitted when the number of pages in the layout changes;     \a newPages is the updated page count.      Subclasses of QAbstractTextDocumentLayout should emit this signal when     the number of pages in the layout has changed. Changes to the page count     are caused by changes to the layout or the document content itself.      \sa pageCount() */
end_comment
begin_comment
comment|/*!     \fn int QAbstractTextDocumentLayout::pageCount() const      Returns the number of pages contained in the layout.      \sa pageCountChanged() */
end_comment
begin_comment
comment|/*!     \fn QSizeF QAbstractTextDocumentLayout::documentSize() const      Returns the total size of the document's layout.      This information can be used by display widgets to update their scroll bars     correctly.      \sa documentSizeChanged(), QTextDocument::pageSize */
end_comment
begin_comment
comment|/*!     \fn void QAbstractTextDocumentLayout::draw(QPainter *painter, const PaintContext&context)      Draws the layout with the given \a painter using the given \a context. */
end_comment
begin_comment
comment|/*!     \fn int QAbstractTextDocumentLayout::hitTest(const QPointF&point, Qt::HitTestAccuracy accuracy) const      Returns the cursor position for the given \a point with the specified     \a accuracy. Returns -1 if no valid cursor position was found. */
end_comment
begin_comment
comment|/*!     \fn void QAbstractTextDocumentLayout::documentChanged(int position, int charsRemoved, int charsAdded)      This function is called whenever the contents of the document change. A     change occurs when text is inserted, removed, or a combination of these     two. The change is specified by \a position, \a charsRemoved, and     \a charsAdded corresponding to the starting character position of the     change, the number of characters removed from the document, and the     number of characters added.      For example, when inserting the text "Hello" into an empty document,     \a charsRemoved would be 0 and \a charsAdded would be 5 (the length of     the string).      Replacing text is a combination of removing and inserting. For example, if     the text "Hello" gets replaced by "Hi", \a charsRemoved would be 5 and     \a charsAdded would be 2.      For subclasses of QAbstractTextDocumentLayout, this is the central function     where a large portion of the work to lay out and position document contents     is done.      For example, in a subclass that only arranges blocks of text, an     implementation of this function would have to do the following:      \list         \li Determine the list of changed \l{QTextBlock}(s) using the parameters             provided.         \li Each QTextBlock object's corresponding QTextLayout object needs to             be processed. You can access the \l{QTextBlock}'s layout using the             QTextBlock::layout() function. This processing should take the             document's page size into consideration.         \li If the total number of pages changed, the pageCountChanged() signal             should be emitted.         \li If the total size changed, the documentSizeChanged() signal should             be emitted.         \li The update() signal should be emitted to schedule a repaint of areas             in the layout that require repainting.     \endlist      \sa QTextLayout */
end_comment
begin_comment
comment|/*!     \class QAbstractTextDocumentLayout::PaintContext     \reentrant      \brief The QAbstractTextDocumentLayout::PaintContext class is a convenience     class defining the parameters used when painting a document's layout.      A paint context is used when rendering custom layouts for QTextDocuments     with the QAbstractTextDocumentLayout::draw() function. It is specified by     a \l {cursorPosition}{cursor position}, \l {palette}{default text color},     \l clip rectangle and a collection of \l selections.      \sa QAbstractTextDocumentLayout */
end_comment
begin_comment
comment|/*!     \fn QAbstractTextDocumentLayout::PaintContext::PaintContext()     \internal */
end_comment
begin_comment
comment|/*!     \variable QAbstractTextDocumentLayout::PaintContext::cursorPosition      \brief the position within the document, where the cursor line should be     drawn.      The default value is -1. */
end_comment
begin_comment
comment|/*!     \variable QAbstractTextDocumentLayout::PaintContext::palette      \brief the default color that is used for the text, when no color is     specified.      The default value is the application's default palette. */
end_comment
begin_comment
comment|/*!     \variable QAbstractTextDocumentLayout::PaintContext::clip      \brief a hint to the layout specifying the area around paragraphs, frames     or text require painting.      Everything outside of this rectangle does not need to be painted.      Specifying a clip rectangle can speed up drawing of large documents     significantly. Note that the clip rectangle is in document coordinates (not     in viewport coordinates). It is not a substitute for a clip region set on     the painter but merely a hint.      The default value is a null rectangle indicating everything needs to be     painted. */
end_comment
begin_comment
comment|/*!     \variable QAbstractTextDocumentLayout::PaintContext::selections      \brief the collection of selections that will be rendered when passing this     paint context to QAbstractTextDocumentLayout's draw() function.      The default value is an empty vector indicating no selection. */
end_comment
begin_comment
comment|/*!     \class QAbstractTextDocumentLayout::Selection     \reentrant      \brief The QAbstractTextDocumentLayout::Selection class is a convenience     class defining the parameters of a selection.      A selection can be used to specify a part of a document that should be     highlighted when drawing custom layouts for QTextDocuments with the     QAbstractTextDocumentLayout::draw() function. It is specified using     \l cursor and a \l format.      \sa QAbstractTextDocumentLayout, PaintContext */
end_comment
begin_comment
comment|/*!     \variable QAbstractTextDocumentLayout::Selection::format      \brief the format of the selection      The default value is QTextFormat::InvalidFormat. */
end_comment
begin_comment
comment|/*!     \variable QAbstractTextDocumentLayout::Selection::cursor     \brief the selection's cursor      The default value is a null cursor. */
end_comment
begin_comment
comment|/*!     Creates a new text document layout for the given \a document. */
end_comment
begin_constructor
DECL|function|QAbstractTextDocumentLayout
name|QAbstractTextDocumentLayout
operator|::
name|QAbstractTextDocumentLayout
parameter_list|(
name|QTextDocument
modifier|*
name|document
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|new
name|QAbstractTextDocumentLayoutPrivate
argument_list|,
name|document
argument_list|)
block|{
name|Q_D
argument_list|(
name|QAbstractTextDocumentLayout
argument_list|)
expr_stmt|;
name|d
operator|->
name|setDocument
argument_list|(
name|document
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QAbstractTextDocumentLayout
name|QAbstractTextDocumentLayout
operator|::
name|QAbstractTextDocumentLayout
parameter_list|(
name|QAbstractTextDocumentLayoutPrivate
modifier|&
name|p
parameter_list|,
name|QTextDocument
modifier|*
name|document
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|p
argument_list|,
name|document
argument_list|)
block|{
name|Q_D
argument_list|(
name|QAbstractTextDocumentLayout
argument_list|)
expr_stmt|;
name|d
operator|->
name|setDocument
argument_list|(
name|document
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     \internal */
end_comment
begin_destructor
DECL|function|~QAbstractTextDocumentLayout
name|QAbstractTextDocumentLayout
operator|::
name|~
name|QAbstractTextDocumentLayout
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     \fn void QAbstractTextDocumentLayout::registerHandler(int objectType, QObject *component)      Registers the given \a component as a handler for items of the given \a objectType.      \note registerHandler() has to be called once for each object type. This     means that there is only one handler for multiple replacement characters     of the same object type. */
end_comment
begin_function
DECL|function|registerHandler
name|void
name|QAbstractTextDocumentLayout
operator|::
name|registerHandler
parameter_list|(
name|int
name|formatType
parameter_list|,
name|QObject
modifier|*
name|component
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QAbstractTextDocumentLayout
argument_list|)
expr_stmt|;
name|QTextObjectInterface
modifier|*
name|iface
init|=
name|qobject_cast
argument_list|<
name|QTextObjectInterface
operator|*
argument_list|>
argument_list|(
name|component
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|iface
condition|)
return|return;
comment|// ### print error message on terminal?
name|connect
argument_list|(
name|component
argument_list|,
name|SIGNAL
argument_list|(
name|destroyed
argument_list|(
name|QObject
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|_q_handlerDestroyed
argument_list|(
name|QObject
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QTextObjectHandler
name|h
decl_stmt|;
name|h
operator|.
name|iface
operator|=
name|iface
expr_stmt|;
name|h
operator|.
name|component
operator|=
name|component
expr_stmt|;
name|d
operator|->
name|handlers
operator|.
name|insert
argument_list|(
name|formatType
argument_list|,
name|h
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns a handler for objects of the given \a objectType. */
end_comment
begin_function
DECL|function|handlerForObject
name|QTextObjectInterface
modifier|*
name|QAbstractTextDocumentLayout
operator|::
name|handlerForObject
parameter_list|(
name|int
name|objectType
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QAbstractTextDocumentLayout
argument_list|)
expr_stmt|;
name|QTextObjectHandler
name|handler
init|=
name|d
operator|->
name|handlers
operator|.
name|value
argument_list|(
name|objectType
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|handler
operator|.
name|component
condition|)
return|return
literal|0
return|;
return|return
name|handler
operator|.
name|iface
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the size of the inline object \a item corresponding to the text     \a format.      \a posInDocument specifies the position of the object within the document.      The default implementation resizes the \a item to the size returned by     the object handler's intrinsicSize() function. This function is called only     within Qt. Subclasses can reimplement this function to customize the     resizing of inline objects. */
end_comment
begin_function
DECL|function|resizeInlineObject
name|void
name|QAbstractTextDocumentLayout
operator|::
name|resizeInlineObject
parameter_list|(
name|QTextInlineObject
name|item
parameter_list|,
name|int
name|posInDocument
parameter_list|,
specifier|const
name|QTextFormat
modifier|&
name|format
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QAbstractTextDocumentLayout
argument_list|)
expr_stmt|;
name|QTextCharFormat
name|f
init|=
name|format
operator|.
name|toCharFormat
argument_list|()
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|f
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QTextObjectHandler
name|handler
init|=
name|d
operator|->
name|handlers
operator|.
name|value
argument_list|(
name|f
operator|.
name|objectType
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|handler
operator|.
name|component
condition|)
return|return;
name|QSizeF
name|s
init|=
name|handler
operator|.
name|iface
operator|->
name|intrinsicSize
argument_list|(
name|document
argument_list|()
argument_list|,
name|posInDocument
argument_list|,
name|format
argument_list|)
decl_stmt|;
name|item
operator|.
name|setWidth
argument_list|(
name|s
operator|.
name|width
argument_list|()
argument_list|)
expr_stmt|;
name|item
operator|.
name|setAscent
argument_list|(
name|s
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|item
operator|.
name|setDescent
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Lays out the inline object \a item using the given text \a format.      \a posInDocument specifies the position of the object within the document.      The default implementation does nothing. This function is called only     within Qt. Subclasses can reimplement this function to customize the     position of inline objects.      \sa drawInlineObject() */
end_comment
begin_function
DECL|function|positionInlineObject
name|void
name|QAbstractTextDocumentLayout
operator|::
name|positionInlineObject
parameter_list|(
name|QTextInlineObject
name|item
parameter_list|,
name|int
name|posInDocument
parameter_list|,
specifier|const
name|QTextFormat
modifier|&
name|format
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|item
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|posInDocument
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|format
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \fn void QAbstractTextDocumentLayout::drawInlineObject(QPainter *painter, const QRectF&rect, QTextInlineObject object, int posInDocument, const QTextFormat&format)      This function is called to draw the inline object, \a object, with the     given \a painter within the rectangle specified by \a rect using the     specified text \a format.      \a posInDocument specifies the position of the object within the document.      The default implementation calls drawObject() on the object handlers. This     function is called only within Qt. Subclasses can reimplement this function     to customize the drawing of inline objects.      \sa draw() */
end_comment
begin_function
DECL|function|drawInlineObject
name|void
name|QAbstractTextDocumentLayout
operator|::
name|drawInlineObject
parameter_list|(
name|QPainter
modifier|*
name|p
parameter_list|,
specifier|const
name|QRectF
modifier|&
name|rect
parameter_list|,
name|QTextInlineObject
name|item
parameter_list|,
name|int
name|posInDocument
parameter_list|,
specifier|const
name|QTextFormat
modifier|&
name|format
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|item
argument_list|)
expr_stmt|;
name|Q_D
argument_list|(
name|QAbstractTextDocumentLayout
argument_list|)
expr_stmt|;
name|QTextCharFormat
name|f
init|=
name|format
operator|.
name|toCharFormat
argument_list|()
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|f
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QTextObjectHandler
name|handler
init|=
name|d
operator|->
name|handlers
operator|.
name|value
argument_list|(
name|f
operator|.
name|objectType
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|handler
operator|.
name|component
condition|)
return|return;
name|handler
operator|.
name|iface
operator|->
name|drawObject
argument_list|(
name|p
argument_list|,
name|rect
argument_list|,
name|document
argument_list|()
argument_list|,
name|posInDocument
argument_list|,
name|format
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|_q_handlerDestroyed
name|void
name|QAbstractTextDocumentLayoutPrivate
operator|::
name|_q_handlerDestroyed
parameter_list|(
name|QObject
modifier|*
name|obj
parameter_list|)
block|{
name|HandlerHash
operator|::
name|Iterator
name|it
init|=
name|handlers
operator|.
name|begin
argument_list|()
decl_stmt|;
while|while
condition|(
name|it
operator|!=
name|handlers
operator|.
name|end
argument_list|()
condition|)
if|if
condition|(
operator|(
operator|*
name|it
operator|)
operator|.
name|component
operator|==
name|obj
condition|)
name|it
operator|=
name|handlers
operator|.
name|erase
argument_list|(
name|it
argument_list|)
expr_stmt|;
else|else
operator|++
name|it
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \internal      Returns the index of the format at position \a pos. */
end_comment
begin_function
DECL|function|formatIndex
name|int
name|QAbstractTextDocumentLayout
operator|::
name|formatIndex
parameter_list|(
name|int
name|pos
parameter_list|)
block|{
name|QTextDocumentPrivate
modifier|*
name|pieceTable
init|=
name|qobject_cast
argument_list|<
name|QTextDocument
operator|*
argument_list|>
argument_list|(
name|parent
argument_list|()
argument_list|)
operator|->
name|docHandle
argument_list|()
decl_stmt|;
return|return
name|pieceTable
operator|->
name|find
argument_list|(
name|pos
argument_list|)
operator|.
name|value
argument_list|()
operator|->
name|format
return|;
block|}
end_function
begin_comment
comment|/*!     \fn QTextCharFormat QAbstractTextDocumentLayout::format(int position)      Returns the character format that is applicable at the given \a position. */
end_comment
begin_function
DECL|function|format
name|QTextCharFormat
name|QAbstractTextDocumentLayout
operator|::
name|format
parameter_list|(
name|int
name|pos
parameter_list|)
block|{
name|QTextDocumentPrivate
modifier|*
name|pieceTable
init|=
name|qobject_cast
argument_list|<
name|QTextDocument
operator|*
argument_list|>
argument_list|(
name|parent
argument_list|()
argument_list|)
operator|->
name|docHandle
argument_list|()
decl_stmt|;
name|int
name|idx
init|=
name|pieceTable
operator|->
name|find
argument_list|(
name|pos
argument_list|)
operator|.
name|value
argument_list|()
operator|->
name|format
decl_stmt|;
return|return
name|pieceTable
operator|->
name|formatCollection
argument_list|()
operator|->
name|charFormat
argument_list|(
name|idx
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the text document that this layout is operating on. */
end_comment
begin_function
DECL|function|document
name|QTextDocument
modifier|*
name|QAbstractTextDocumentLayout
operator|::
name|document
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QAbstractTextDocumentLayout
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|document
return|;
block|}
end_function
begin_comment
comment|/*!     \fn QString QAbstractTextDocumentLayout::anchorAt(const QPointF&position) const      Returns the reference of the anchor the given \a position, or an empty     string if no anchor exists at that point. */
end_comment
begin_function
DECL|function|anchorAt
name|QString
name|QAbstractTextDocumentLayout
operator|::
name|anchorAt
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|pos
parameter_list|)
specifier|const
block|{
name|int
name|cursorPos
init|=
name|hitTest
argument_list|(
name|pos
argument_list|,
name|Qt
operator|::
name|ExactHit
argument_list|)
decl_stmt|;
if|if
condition|(
name|cursorPos
operator|==
operator|-
literal|1
condition|)
return|return
name|QString
argument_list|()
return|;
comment|// compensate for preedit in the hit text block
name|QTextBlock
name|block
init|=
name|document
argument_list|()
operator|->
name|firstBlock
argument_list|()
decl_stmt|;
while|while
condition|(
name|block
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|QRectF
name|blockBr
init|=
name|blockBoundingRect
argument_list|(
name|block
argument_list|)
decl_stmt|;
if|if
condition|(
name|blockBr
operator|.
name|contains
argument_list|(
name|pos
argument_list|)
condition|)
block|{
name|QTextLayout
modifier|*
name|layout
init|=
name|block
operator|.
name|layout
argument_list|()
decl_stmt|;
name|int
name|relativeCursorPos
init|=
name|cursorPos
operator|-
name|block
operator|.
name|position
argument_list|()
decl_stmt|;
specifier|const
name|int
name|preeditLength
init|=
name|layout
condition|?
name|layout
operator|->
name|preeditAreaText
argument_list|()
operator|.
name|length
argument_list|()
else|:
literal|0
decl_stmt|;
if|if
condition|(
name|preeditLength
operator|>
literal|0
operator|&&
name|relativeCursorPos
operator|>
name|layout
operator|->
name|preeditAreaPosition
argument_list|()
condition|)
name|cursorPos
operator|-=
name|qMin
argument_list|(
name|cursorPos
operator|-
name|layout
operator|->
name|preeditAreaPosition
argument_list|()
argument_list|,
name|preeditLength
argument_list|)
expr_stmt|;
break|break;
block|}
name|block
operator|=
name|block
operator|.
name|next
argument_list|()
expr_stmt|;
block|}
name|QTextDocumentPrivate
modifier|*
name|pieceTable
init|=
name|qobject_cast
argument_list|<
specifier|const
name|QTextDocument
operator|*
argument_list|>
argument_list|(
name|parent
argument_list|()
argument_list|)
operator|->
name|docHandle
argument_list|()
decl_stmt|;
name|QTextDocumentPrivate
operator|::
name|FragmentIterator
name|it
init|=
name|pieceTable
operator|->
name|find
argument_list|(
name|cursorPos
argument_list|)
decl_stmt|;
name|QTextCharFormat
name|fmt
init|=
name|pieceTable
operator|->
name|formatCollection
argument_list|()
operator|->
name|charFormat
argument_list|(
name|it
operator|->
name|format
argument_list|)
decl_stmt|;
return|return
name|fmt
operator|.
name|anchorHref
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     \fn QRectF QAbstractTextDocumentLayout::frameBoundingRect(QTextFrame *frame) const      Returns the bounding rectangle of \a frame. */
end_comment
begin_comment
comment|/*!     \fn QRectF QAbstractTextDocumentLayout::blockBoundingRect(const QTextBlock&block) const      Returns the bounding rectangle of \a block. */
end_comment
begin_comment
comment|/*!     Sets the paint device used for rendering the document's layout to the given     \a device.      \sa paintDevice() */
end_comment
begin_function
DECL|function|setPaintDevice
name|void
name|QAbstractTextDocumentLayout
operator|::
name|setPaintDevice
parameter_list|(
name|QPaintDevice
modifier|*
name|device
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QAbstractTextDocumentLayout
argument_list|)
expr_stmt|;
name|d
operator|->
name|paintDevice
operator|=
name|device
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the paint device used to render the document's layout.      \sa setPaintDevice() */
end_comment
begin_function
DECL|function|paintDevice
name|QPaintDevice
modifier|*
name|QAbstractTextDocumentLayout
operator|::
name|paintDevice
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QAbstractTextDocumentLayout
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|paintDevice
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"moc_qabstracttextdocumentlayout.cpp"
end_include
end_unit
