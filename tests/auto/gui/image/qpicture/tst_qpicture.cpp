begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qpicture.h>
end_include
begin_include
include|#
directive|include
file|<qpainter.h>
end_include
begin_include
include|#
directive|include
file|<qimage.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_WIDGETS
end_ifndef
begin_include
include|#
directive|include
file|<qdesktopwidget.h>
end_include
begin_include
include|#
directive|include
file|<qapplication.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<limits.h>
end_include
begin_class
DECL|class|tst_QPicture
class|class
name|tst_QPicture
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QPicture
parameter_list|()
constructor_decl|;
private|private
name|slots
private|:
name|void
name|getSetCheck
parameter_list|()
function_decl|;
name|void
name|devType
parameter_list|()
function_decl|;
name|void
name|paintingActive
parameter_list|()
function_decl|;
name|void
name|boundingRect
parameter_list|()
function_decl|;
name|void
name|swap
parameter_list|()
function_decl|;
name|void
name|operator_lt_lt
parameter_list|()
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_WIDGETS
name|void
name|save_restore
parameter_list|()
function_decl|;
endif|#
directive|endif
name|void
name|boundaryValues_data
parameter_list|()
function_decl|;
name|void
name|boundaryValues
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_comment
comment|// Testing get/set functions
end_comment
begin_function
DECL|function|getSetCheck
name|void
name|tst_QPicture
operator|::
name|getSetCheck
parameter_list|()
block|{
name|QPictureIO
name|obj1
decl_stmt|;
comment|// const QPicture& QPictureIO::picture()
comment|// void QPictureIO::setPicture(const QPicture&)
comment|// const char * QPictureIO::format()
comment|// void QPictureIO::setFormat(const char *)
specifier|const
name|char
name|var2
index|[]
init|=
literal|"PNG"
decl_stmt|;
name|obj1
operator|.
name|setFormat
argument_list|(
name|var2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|var2
argument_list|,
name|obj1
operator|.
name|format
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setFormat
argument_list|(
operator|(
name|char
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// The format is stored internally in a QString, so return is always a valid char *
name|QVERIFY
argument_list|(
name|QString
argument_list|(
name|obj1
operator|.
name|format
argument_list|()
argument_list|)
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
comment|// const char * QPictureIO::parameters()
comment|// void QPictureIO::setParameters(const char *)
specifier|const
name|char
name|var3
index|[]
init|=
literal|"Bogus data"
decl_stmt|;
name|obj1
operator|.
name|setParameters
argument_list|(
name|var3
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|var3
argument_list|,
name|obj1
operator|.
name|parameters
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setParameters
argument_list|(
operator|(
name|char
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// The format is stored internally in a QString, so return is always a valid char *
name|QVERIFY
argument_list|(
name|QString
argument_list|(
name|obj1
operator|.
name|parameters
argument_list|()
argument_list|)
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|tst_QPicture
name|tst_QPicture
operator|::
name|tst_QPicture
parameter_list|()
block|{ }
end_constructor
begin_function
DECL|function|devType
name|void
name|tst_QPicture
operator|::
name|devType
parameter_list|()
block|{
name|QPicture
name|p
decl_stmt|;
name|QCOMPARE
argument_list|(
name|p
operator|.
name|devType
argument_list|()
argument_list|,
operator|(
name|int
operator|)
name|QInternal
operator|::
name|Picture
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|paintingActive
name|void
name|tst_QPicture
operator|::
name|paintingActive
parameter_list|()
block|{
comment|// actually implemented in QPainter but QPicture is a good
comment|// example of an external paint device
name|QPicture
name|p
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|p
operator|.
name|paintingActive
argument_list|()
argument_list|)
expr_stmt|;
name|QPainter
name|pt
argument_list|(
operator|&
name|p
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|p
operator|.
name|paintingActive
argument_list|()
argument_list|)
expr_stmt|;
name|pt
operator|.
name|end
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|p
operator|.
name|paintingActive
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|boundingRect
name|void
name|tst_QPicture
operator|::
name|boundingRect
parameter_list|()
block|{
name|QPicture
name|p1
decl_stmt|;
comment|// default value
name|QVERIFY
argument_list|(
operator|!
name|p1
operator|.
name|boundingRect
argument_list|()
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QRect
name|r1
argument_list|(
literal|20
argument_list|,
literal|30
argument_list|,
literal|5
argument_list|,
literal|15
argument_list|)
decl_stmt|;
name|p1
operator|.
name|setBoundingRect
argument_list|(
name|r1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|p1
operator|.
name|boundingRect
argument_list|()
argument_list|,
name|r1
argument_list|)
expr_stmt|;
name|p1
operator|.
name|setBoundingRect
argument_list|(
name|QRect
argument_list|()
argument_list|)
expr_stmt|;
name|QPainter
name|pt
argument_list|(
operator|&
name|p1
argument_list|)
decl_stmt|;
name|pt
operator|.
name|drawLine
argument_list|(
literal|10
argument_list|,
literal|20
argument_list|,
literal|110
argument_list|,
literal|80
argument_list|)
expr_stmt|;
name|pt
operator|.
name|end
argument_list|()
expr_stmt|;
comment|// assignment and copy constructor
name|QRect
name|r2
argument_list|(
literal|10
argument_list|,
literal|20
argument_list|,
literal|100
argument_list|,
literal|60
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|p1
operator|.
name|boundingRect
argument_list|()
argument_list|,
name|r2
argument_list|)
expr_stmt|;
name|QPicture
name|p2
argument_list|(
name|p1
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|p1
operator|.
name|boundingRect
argument_list|()
argument_list|,
name|r2
argument_list|)
expr_stmt|;
name|QPicture
name|p3
decl_stmt|;
name|p3
operator|=
name|p1
expr_stmt|;
name|QCOMPARE
argument_list|(
name|p1
operator|.
name|boundingRect
argument_list|()
argument_list|,
name|r2
argument_list|)
expr_stmt|;
block|{
name|QPicture
name|p4
decl_stmt|;
name|QPainter
name|p
argument_list|(
operator|&
name|p4
argument_list|)
decl_stmt|;
name|p
operator|.
name|drawLine
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|5
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|p
operator|.
name|drawLine
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|p
operator|.
name|end
argument_list|()
expr_stmt|;
name|QRect
name|r3
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|5
argument_list|,
literal|5
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|p4
operator|.
name|boundingRect
argument_list|()
argument_list|,
name|r3
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|swap
name|void
name|tst_QPicture
operator|::
name|swap
parameter_list|()
block|{
name|QPicture
name|p1
decl_stmt|,
name|p2
decl_stmt|;
name|QPainter
argument_list|(
operator|&
name|p1
argument_list|)
operator|.
name|drawLine
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|5
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|QPainter
argument_list|(
operator|&
name|p2
argument_list|)
operator|.
name|drawLine
argument_list|(
literal|0
argument_list|,
literal|3
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|p1
operator|.
name|boundingRect
argument_list|()
argument_list|,
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|5
argument_list|,
literal|5
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|p2
operator|.
name|boundingRect
argument_list|()
argument_list|,
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|3
argument_list|,
literal|3
argument_list|)
argument_list|)
expr_stmt|;
name|p1
operator|.
name|swap
argument_list|(
name|p2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|p1
operator|.
name|boundingRect
argument_list|()
argument_list|,
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|3
argument_list|,
literal|3
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|p2
operator|.
name|boundingRect
argument_list|()
argument_list|,
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|5
argument_list|,
literal|5
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// operator<< and operator>>
end_comment
begin_function
DECL|function|operator_lt_lt
name|void
name|tst_QPicture
operator|::
name|operator_lt_lt
parameter_list|()
block|{
comment|// streaming of null pictures
block|{
name|QPicture
name|pic1
decl_stmt|,
name|pic2
decl_stmt|;
name|QByteArray
name|ba
argument_list|(
literal|100
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|QDataStream
name|str1
argument_list|(
operator|&
name|ba
argument_list|,
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
decl_stmt|;
name|str1
operator|<<
name|pic1
expr_stmt|;
name|QDataStream
name|str2
argument_list|(
operator|&
name|ba
argument_list|,
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
decl_stmt|;
name|str2
operator|>>
name|pic2
expr_stmt|;
name|QVERIFY
argument_list|(
name|pic2
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|// picture with a simple line, checking bitwise equality
block|{
name|QPicture
name|pic1
decl_stmt|,
name|pic2
decl_stmt|;
name|QPainter
name|p
argument_list|(
operator|&
name|pic1
argument_list|)
decl_stmt|;
name|p
operator|.
name|drawLine
argument_list|(
literal|10
argument_list|,
literal|20
argument_list|,
literal|30
argument_list|,
literal|40
argument_list|)
expr_stmt|;
name|p
operator|.
name|end
argument_list|()
expr_stmt|;
name|QByteArray
name|ba
argument_list|(
literal|10
operator|*
name|pic1
operator|.
name|size
argument_list|()
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|QDataStream
name|str1
argument_list|(
operator|&
name|ba
argument_list|,
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
decl_stmt|;
name|str1
operator|<<
name|pic1
expr_stmt|;
name|QDataStream
name|str2
argument_list|(
operator|&
name|ba
argument_list|,
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
decl_stmt|;
name|str2
operator|>>
name|pic2
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pic1
operator|.
name|size
argument_list|()
argument_list|,
name|pic2
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|memcmp
argument_list|(
name|pic1
operator|.
name|data
argument_list|()
argument_list|,
name|pic2
operator|.
name|data
argument_list|()
argument_list|,
name|pic1
operator|.
name|size
argument_list|()
argument_list|)
operator|==
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_WIDGETS
end_ifndef
begin_function
DECL|function|scalePoint
specifier|static
name|QPointF
name|scalePoint
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|point
parameter_list|,
name|QPaintDevice
modifier|*
name|sourceDevice
parameter_list|,
name|QPaintDevice
modifier|*
name|destDevice
parameter_list|)
block|{
return|return
name|QPointF
argument_list|(
name|point
operator|.
name|x
argument_list|()
operator|*
name|qreal
argument_list|(
name|destDevice
operator|->
name|logicalDpiX
argument_list|()
argument_list|)
operator|/
name|qreal
argument_list|(
name|sourceDevice
operator|->
name|logicalDpiX
argument_list|()
argument_list|)
argument_list|,
name|point
operator|.
name|y
argument_list|()
operator|*
name|qreal
argument_list|(
name|destDevice
operator|->
name|logicalDpiY
argument_list|()
argument_list|)
operator|/
name|qreal
argument_list|(
name|sourceDevice
operator|->
name|logicalDpiY
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|scaleRect
specifier|static
name|QRectF
name|scaleRect
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|rect
parameter_list|,
name|QPaintDevice
modifier|*
name|sourceDevice
parameter_list|,
name|QPaintDevice
modifier|*
name|destDevice
parameter_list|)
block|{
return|return
name|QRectF
argument_list|(
name|rect
operator|.
name|left
argument_list|()
operator|*
name|qreal
argument_list|(
name|destDevice
operator|->
name|logicalDpiX
argument_list|()
argument_list|)
operator|/
name|qreal
argument_list|(
name|sourceDevice
operator|->
name|logicalDpiX
argument_list|()
argument_list|)
argument_list|,
name|rect
operator|.
name|top
argument_list|()
operator|*
name|qreal
argument_list|(
name|destDevice
operator|->
name|logicalDpiY
argument_list|()
argument_list|)
operator|/
name|qreal
argument_list|(
name|sourceDevice
operator|->
name|logicalDpiY
argument_list|()
argument_list|)
argument_list|,
name|rect
operator|.
name|width
argument_list|()
operator|*
name|qreal
argument_list|(
name|destDevice
operator|->
name|logicalDpiX
argument_list|()
argument_list|)
operator|/
name|qreal
argument_list|(
name|sourceDevice
operator|->
name|logicalDpiX
argument_list|()
argument_list|)
argument_list|,
name|rect
operator|.
name|height
argument_list|()
operator|*
name|qreal
argument_list|(
name|destDevice
operator|->
name|logicalDpiY
argument_list|()
argument_list|)
operator|/
name|qreal
argument_list|(
name|sourceDevice
operator|->
name|logicalDpiY
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|paintStuff
specifier|static
name|void
name|paintStuff
parameter_list|(
name|QPainter
modifier|*
name|p
parameter_list|)
block|{
name|QPaintDevice
modifier|*
name|screenDevice
init|=
name|QApplication
operator|::
name|desktop
argument_list|()
decl_stmt|;
name|p
operator|->
name|drawRect
argument_list|(
name|scaleRect
argument_list|(
name|QRectF
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|,
name|screenDevice
argument_list|,
name|p
operator|->
name|device
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|p
operator|->
name|save
argument_list|()
expr_stmt|;
name|p
operator|->
name|translate
argument_list|(
name|scalePoint
argument_list|(
name|QPointF
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
argument_list|,
name|screenDevice
argument_list|,
name|p
operator|->
name|device
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|p
operator|->
name|restore
argument_list|()
expr_stmt|;
name|p
operator|->
name|drawRect
argument_list|(
name|scaleRect
argument_list|(
name|QRectF
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|,
name|screenDevice
argument_list|,
name|p
operator|->
name|device
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/* See task: 41469    Problem is that the state is not properly restored if the basestate of    the painter is different when the picture data was created compared to    the base state of the painter when it is played back.  */
end_comment
begin_function
DECL|function|save_restore
name|void
name|tst_QPicture
operator|::
name|save_restore
parameter_list|()
block|{
name|QPicture
name|pic
decl_stmt|;
name|QPainter
name|p
decl_stmt|;
name|p
operator|.
name|begin
argument_list|(
operator|&
name|pic
argument_list|)
expr_stmt|;
name|paintStuff
argument_list|(
operator|&
name|p
argument_list|)
expr_stmt|;
name|p
operator|.
name|end
argument_list|()
expr_stmt|;
name|QPixmap
name|pix1
argument_list|(
literal|300
argument_list|,
literal|300
argument_list|)
decl_stmt|;
name|pix1
operator|.
name|fill
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
name|p
operator|.
name|begin
argument_list|(
operator|&
name|pix1
argument_list|)
expr_stmt|;
name|p
operator|.
name|drawPicture
argument_list|(
literal|50
argument_list|,
literal|50
argument_list|,
name|pic
argument_list|)
expr_stmt|;
name|p
operator|.
name|end
argument_list|()
expr_stmt|;
name|QPixmap
name|pix2
argument_list|(
literal|300
argument_list|,
literal|300
argument_list|)
decl_stmt|;
name|pix2
operator|.
name|fill
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
name|p
operator|.
name|begin
argument_list|(
operator|&
name|pix2
argument_list|)
expr_stmt|;
name|p
operator|.
name|translate
argument_list|(
literal|50
argument_list|,
literal|50
argument_list|)
expr_stmt|;
name|paintStuff
argument_list|(
operator|&
name|p
argument_list|)
expr_stmt|;
name|p
operator|.
name|end
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|pix1
operator|.
name|toImage
argument_list|()
operator|==
name|pix2
operator|.
name|toImage
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|boundaryValues_data
name|void
name|tst_QPicture
operator|::
name|boundaryValues_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"x"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"y"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"max x"
argument_list|)
operator|<<
name|INT_MAX
operator|<<
literal|50
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"max y"
argument_list|)
operator|<<
literal|50
operator|<<
name|INT_MAX
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"max x and y"
argument_list|)
operator|<<
name|INT_MAX
operator|<<
name|INT_MAX
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"min x"
argument_list|)
operator|<<
name|INT_MIN
operator|<<
literal|50
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"min y"
argument_list|)
operator|<<
literal|50
operator|<<
name|INT_MIN
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"min x and y"
argument_list|)
operator|<<
name|INT_MIN
operator|<<
name|INT_MIN
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"min x, max y"
argument_list|)
operator|<<
name|INT_MIN
operator|<<
name|INT_MAX
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"max x, min y"
argument_list|)
operator|<<
name|INT_MAX
operator|<<
name|INT_MIN
expr_stmt|;
block|}
end_function
begin_function
DECL|function|boundaryValues
name|void
name|tst_QPicture
operator|::
name|boundaryValues
parameter_list|()
block|{
name|QPicture
name|picture
decl_stmt|;
name|QPainter
name|painter
decl_stmt|;
name|painter
operator|.
name|begin
argument_list|(
operator|&
name|picture
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|x
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|y
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawPoint
argument_list|(
name|QPoint
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|.
name|end
argument_list|()
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QPicture
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qpicture.moc"
end_include
end_unit
