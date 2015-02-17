begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets/QOpenGLWidget>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLFunctions>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPainter>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QGraphicsView>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QGraphicsScene>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QGraphicsRectItem>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QVBoxLayout>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QPushButton>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QSignalSpy>
end_include
begin_class
DECL|class|tst_QOpenGLWidget
class|class
name|tst_QOpenGLWidget
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|create
parameter_list|()
function_decl|;
name|void
name|clearAndGrab
parameter_list|()
function_decl|;
name|void
name|clearAndResizeAndGrab
parameter_list|()
function_decl|;
name|void
name|createNonTopLevel
parameter_list|()
function_decl|;
name|void
name|painter
parameter_list|()
function_decl|;
name|void
name|reparentToAlreadyCreated
parameter_list|()
function_decl|;
name|void
name|reparentToNotYetCreated
parameter_list|()
function_decl|;
name|void
name|asViewport
parameter_list|()
function_decl|;
name|void
name|requestUpdate
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|create
name|void
name|tst_QOpenGLWidget
operator|::
name|create
parameter_list|()
block|{
name|QScopedPointer
argument_list|<
name|QOpenGLWidget
argument_list|>
name|w
argument_list|(
operator|new
name|QOpenGLWidget
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|w
operator|->
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QSignalSpy
name|frameSwappedSpy
argument_list|(
name|w
operator|.
name|data
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|frameSwapped
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|w
operator|->
name|show
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
name|w
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|frameSwappedSpy
operator|.
name|count
argument_list|()
operator|>
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|w
operator|->
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|w
operator|->
name|context
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|w
operator|->
name|context
argument_list|()
operator|->
name|format
argument_list|()
operator|==
name|w
operator|->
name|format
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|w
operator|->
name|defaultFramebufferObject
argument_list|()
operator|!=
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|ClearWidget
class|class
name|ClearWidget
super|:
specifier|public
name|QOpenGLWidget
super|,
specifier|protected
name|QOpenGLFunctions
block|{
public|public:
DECL|function|ClearWidget
name|ClearWidget
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|,
name|int
name|expectedWidth
parameter_list|,
name|int
name|expectedHeight
parameter_list|)
member_init_list|:
name|QOpenGLWidget
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|m_initCalled
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_paintCalled
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_resizeCalled
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_resizeOk
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_w
argument_list|(
name|expectedWidth
argument_list|)
member_init_list|,
name|m_h
argument_list|(
name|expectedHeight
argument_list|)
block|{ }
name|void
name|initializeGL
parameter_list|()
name|Q_DECL_OVERRIDE
block|{
name|m_initCalled
operator|=
literal|true
expr_stmt|;
name|initializeOpenGLFunctions
argument_list|()
expr_stmt|;
block|}
name|void
name|paintGL
parameter_list|()
name|Q_DECL_OVERRIDE
block|{
name|m_paintCalled
operator|=
literal|true
expr_stmt|;
name|glClearColor
argument_list|(
literal|1.0f
argument_list|,
literal|0.0f
argument_list|,
literal|0.0f
argument_list|,
literal|1.0f
argument_list|)
expr_stmt|;
name|glClear
argument_list|(
name|GL_COLOR_BUFFER_BIT
argument_list|)
expr_stmt|;
block|}
name|void
name|resizeGL
parameter_list|(
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|)
name|Q_DECL_OVERRIDE
block|{
name|m_resizeCalled
operator|=
literal|true
expr_stmt|;
name|m_resizeOk
operator|=
name|w
operator|==
name|m_w
operator|&&
name|h
operator|==
name|m_h
expr_stmt|;
block|}
DECL|member|m_initCalled
name|bool
name|m_initCalled
decl_stmt|;
DECL|member|m_paintCalled
name|bool
name|m_paintCalled
decl_stmt|;
DECL|member|m_resizeCalled
name|bool
name|m_resizeCalled
decl_stmt|;
DECL|member|m_resizeOk
name|bool
name|m_resizeOk
decl_stmt|;
DECL|member|m_w
name|int
name|m_w
decl_stmt|;
DECL|member|m_h
name|int
name|m_h
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|clearAndGrab
name|void
name|tst_QOpenGLWidget
operator|::
name|clearAndGrab
parameter_list|()
block|{
name|QScopedPointer
argument_list|<
name|ClearWidget
argument_list|>
name|w
argument_list|(
operator|new
name|ClearWidget
argument_list|(
literal|0
argument_list|,
literal|800
argument_list|,
literal|600
argument_list|)
argument_list|)
decl_stmt|;
name|w
operator|->
name|resize
argument_list|(
literal|800
argument_list|,
literal|600
argument_list|)
expr_stmt|;
name|w
operator|->
name|show
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
name|w
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|w
operator|->
name|m_initCalled
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|w
operator|->
name|m_resizeCalled
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|w
operator|->
name|m_resizeOk
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|w
operator|->
name|m_paintCalled
argument_list|)
expr_stmt|;
name|QImage
name|image
init|=
name|w
operator|->
name|grabFramebuffer
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|image
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|image
operator|.
name|width
argument_list|()
argument_list|,
name|w
operator|->
name|width
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|image
operator|.
name|height
argument_list|()
argument_list|,
name|w
operator|->
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|image
operator|.
name|pixel
argument_list|(
literal|30
argument_list|,
literal|40
argument_list|)
operator|==
name|qRgb
argument_list|(
literal|255
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|clearAndResizeAndGrab
name|void
name|tst_QOpenGLWidget
operator|::
name|clearAndResizeAndGrab
parameter_list|()
block|{
name|QScopedPointer
argument_list|<
name|QOpenGLWidget
argument_list|>
name|w
argument_list|(
operator|new
name|ClearWidget
argument_list|(
literal|0
argument_list|,
literal|640
argument_list|,
literal|480
argument_list|)
argument_list|)
decl_stmt|;
name|w
operator|->
name|resize
argument_list|(
literal|640
argument_list|,
literal|480
argument_list|)
expr_stmt|;
name|w
operator|->
name|show
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
name|w
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
name|QImage
name|image
init|=
name|w
operator|->
name|grabFramebuffer
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|image
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|image
operator|.
name|width
argument_list|()
argument_list|,
name|w
operator|->
name|width
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|image
operator|.
name|height
argument_list|()
argument_list|,
name|w
operator|->
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|w
operator|->
name|resize
argument_list|(
literal|800
argument_list|,
literal|600
argument_list|)
expr_stmt|;
name|image
operator|=
name|w
operator|->
name|grabFramebuffer
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|image
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|image
operator|.
name|width
argument_list|()
argument_list|,
literal|800
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|image
operator|.
name|height
argument_list|()
argument_list|,
literal|600
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|image
operator|.
name|width
argument_list|()
argument_list|,
name|w
operator|->
name|width
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|image
operator|.
name|height
argument_list|()
argument_list|,
name|w
operator|->
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|image
operator|.
name|pixel
argument_list|(
literal|30
argument_list|,
literal|40
argument_list|)
operator|==
name|qRgb
argument_list|(
literal|255
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createNonTopLevel
name|void
name|tst_QOpenGLWidget
operator|::
name|createNonTopLevel
parameter_list|()
block|{
name|QWidget
name|w
decl_stmt|;
name|ClearWidget
modifier|*
name|glw
init|=
operator|new
name|ClearWidget
argument_list|(
operator|&
name|w
argument_list|,
literal|600
argument_list|,
literal|700
argument_list|)
decl_stmt|;
name|QSignalSpy
name|frameSwappedSpy
argument_list|(
name|glw
argument_list|,
name|SIGNAL
argument_list|(
name|frameSwapped
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|w
operator|.
name|resize
argument_list|(
literal|400
argument_list|,
literal|400
argument_list|)
expr_stmt|;
name|w
operator|.
name|show
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
operator|&
name|w
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|frameSwappedSpy
operator|.
name|count
argument_list|()
operator|>
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|glw
operator|->
name|m_resizeCalled
argument_list|)
expr_stmt|;
name|glw
operator|->
name|m_resizeCalled
operator|=
literal|false
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|glw
operator|->
name|m_resizeOk
argument_list|)
expr_stmt|;
name|glw
operator|->
name|resize
argument_list|(
literal|600
argument_list|,
literal|700
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|glw
operator|->
name|m_initCalled
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|glw
operator|->
name|m_resizeCalled
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|glw
operator|->
name|m_resizeOk
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|glw
operator|->
name|m_paintCalled
argument_list|)
expr_stmt|;
name|QImage
name|image
init|=
name|glw
operator|->
name|grabFramebuffer
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|image
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|image
operator|.
name|width
argument_list|()
argument_list|,
name|glw
operator|->
name|width
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|image
operator|.
name|height
argument_list|()
argument_list|,
name|glw
operator|->
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|image
operator|.
name|pixel
argument_list|(
literal|30
argument_list|,
literal|40
argument_list|)
operator|==
name|qRgb
argument_list|(
literal|255
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|glw
operator|->
name|doneCurrent
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
argument_list|)
expr_stmt|;
name|glw
operator|->
name|makeCurrent
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
operator|==
name|glw
operator|->
name|context
argument_list|()
operator|&&
name|glw
operator|->
name|context
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|PainterWidget
class|class
name|PainterWidget
super|:
specifier|public
name|QOpenGLWidget
super|,
specifier|protected
name|QOpenGLFunctions
block|{
public|public:
DECL|function|PainterWidget
name|PainterWidget
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QOpenGLWidget
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|m_clear
argument_list|(
literal|false
argument_list|)
block|{ }
name|void
name|initializeGL
parameter_list|()
name|Q_DECL_OVERRIDE
block|{
name|initializeOpenGLFunctions
argument_list|()
expr_stmt|;
block|}
name|void
name|paintGL
parameter_list|()
name|Q_DECL_OVERRIDE
block|{
name|QPainter
name|p
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|p
operator|.
name|device
argument_list|()
operator|->
name|width
argument_list|()
argument_list|,
name|width
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|p
operator|.
name|device
argument_list|()
operator|->
name|height
argument_list|()
argument_list|,
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|p
operator|.
name|fillRect
argument_list|(
name|QRect
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|QSize
argument_list|(
name|width
argument_list|()
argument_list|,
name|height
argument_list|()
argument_list|)
argument_list|)
argument_list|,
name|Qt
operator|::
name|blue
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_clear
condition|)
block|{
name|p
operator|.
name|beginNativePainting
argument_list|()
expr_stmt|;
name|glClearColor
argument_list|(
literal|0.0f
argument_list|,
literal|1.0f
argument_list|,
literal|0.0f
argument_list|,
literal|1.0f
argument_list|)
expr_stmt|;
name|glClear
argument_list|(
name|GL_COLOR_BUFFER_BIT
argument_list|)
expr_stmt|;
name|p
operator|.
name|endNativePainting
argument_list|()
expr_stmt|;
block|}
block|}
DECL|member|m_clear
name|bool
name|m_clear
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|painter
name|void
name|tst_QOpenGLWidget
operator|::
name|painter
parameter_list|()
block|{
name|QWidget
name|w
decl_stmt|;
name|PainterWidget
modifier|*
name|glw
init|=
operator|new
name|PainterWidget
argument_list|(
operator|&
name|w
argument_list|)
decl_stmt|;
name|w
operator|.
name|resize
argument_list|(
literal|640
argument_list|,
literal|480
argument_list|)
expr_stmt|;
name|glw
operator|->
name|resize
argument_list|(
literal|320
argument_list|,
literal|200
argument_list|)
expr_stmt|;
name|w
operator|.
name|show
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
operator|&
name|w
argument_list|)
expr_stmt|;
name|QImage
name|image
init|=
name|glw
operator|->
name|grabFramebuffer
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|image
operator|.
name|width
argument_list|()
argument_list|,
name|glw
operator|->
name|width
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|image
operator|.
name|height
argument_list|()
argument_list|,
name|glw
operator|->
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|image
operator|.
name|pixel
argument_list|(
literal|20
argument_list|,
literal|10
argument_list|)
operator|==
name|qRgb
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|255
argument_list|)
argument_list|)
expr_stmt|;
name|glw
operator|->
name|m_clear
operator|=
literal|true
expr_stmt|;
name|image
operator|=
name|glw
operator|->
name|grabFramebuffer
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|image
operator|.
name|pixel
argument_list|(
literal|20
argument_list|,
literal|10
argument_list|)
operator|==
name|qRgb
argument_list|(
literal|0
argument_list|,
literal|255
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|reparentToAlreadyCreated
name|void
name|tst_QOpenGLWidget
operator|::
name|reparentToAlreadyCreated
parameter_list|()
block|{
name|QWidget
name|w1
decl_stmt|;
name|PainterWidget
modifier|*
name|glw
init|=
operator|new
name|PainterWidget
argument_list|(
operator|&
name|w1
argument_list|)
decl_stmt|;
name|w1
operator|.
name|resize
argument_list|(
literal|640
argument_list|,
literal|480
argument_list|)
expr_stmt|;
name|glw
operator|->
name|resize
argument_list|(
literal|320
argument_list|,
literal|200
argument_list|)
expr_stmt|;
name|w1
operator|.
name|show
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
operator|&
name|w1
argument_list|)
expr_stmt|;
name|QWidget
name|w2
decl_stmt|;
name|w2
operator|.
name|show
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
operator|&
name|w2
argument_list|)
expr_stmt|;
name|glw
operator|->
name|setParent
argument_list|(
operator|&
name|w2
argument_list|)
expr_stmt|;
name|glw
operator|->
name|show
argument_list|()
expr_stmt|;
name|QImage
name|image
init|=
name|glw
operator|->
name|grabFramebuffer
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|image
operator|.
name|width
argument_list|()
argument_list|,
literal|320
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|image
operator|.
name|height
argument_list|()
argument_list|,
literal|200
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|image
operator|.
name|pixel
argument_list|(
literal|20
argument_list|,
literal|10
argument_list|)
operator|==
name|qRgb
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|255
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|reparentToNotYetCreated
name|void
name|tst_QOpenGLWidget
operator|::
name|reparentToNotYetCreated
parameter_list|()
block|{
name|QWidget
name|w1
decl_stmt|;
name|PainterWidget
modifier|*
name|glw
init|=
operator|new
name|PainterWidget
argument_list|(
operator|&
name|w1
argument_list|)
decl_stmt|;
name|w1
operator|.
name|resize
argument_list|(
literal|640
argument_list|,
literal|480
argument_list|)
expr_stmt|;
name|glw
operator|->
name|resize
argument_list|(
literal|320
argument_list|,
literal|200
argument_list|)
expr_stmt|;
name|w1
operator|.
name|show
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
operator|&
name|w1
argument_list|)
expr_stmt|;
name|QWidget
name|w2
decl_stmt|;
name|glw
operator|->
name|setParent
argument_list|(
operator|&
name|w2
argument_list|)
expr_stmt|;
name|w2
operator|.
name|show
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
operator|&
name|w2
argument_list|)
expr_stmt|;
name|QImage
name|image
init|=
name|glw
operator|->
name|grabFramebuffer
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|image
operator|.
name|width
argument_list|()
argument_list|,
literal|320
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|image
operator|.
name|height
argument_list|()
argument_list|,
literal|200
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|image
operator|.
name|pixel
argument_list|(
literal|20
argument_list|,
literal|10
argument_list|)
operator|==
name|qRgb
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|255
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|CountingGraphicsView
class|class
name|CountingGraphicsView
super|:
specifier|public
name|QGraphicsView
block|{
public|public:
DECL|function|CountingGraphicsView
name|CountingGraphicsView
parameter_list|()
member_init_list|:
name|m_count
argument_list|(
literal|0
argument_list|)
block|{ }
DECL|function|paintCount
name|int
name|paintCount
parameter_list|()
specifier|const
block|{
return|return
name|m_count
return|;
block|}
DECL|function|resetPaintCount
name|void
name|resetPaintCount
parameter_list|()
block|{
name|m_count
operator|=
literal|0
expr_stmt|;
block|}
protected|protected:
DECL|member|Q_DECL_OVERRIDE
name|void
name|drawForeground
parameter_list|(
name|QPainter
modifier|*
parameter_list|,
specifier|const
name|QRectF
modifier|&
parameter_list|)
name|Q_DECL_OVERRIDE
function_decl|;
DECL|member|m_count
name|int
name|m_count
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|drawForeground
name|void
name|CountingGraphicsView
operator|::
name|drawForeground
parameter_list|(
name|QPainter
modifier|*
parameter_list|,
specifier|const
name|QRectF
modifier|&
parameter_list|)
block|{
operator|++
name|m_count
expr_stmt|;
block|}
end_function
begin_function
DECL|function|asViewport
name|void
name|tst_QOpenGLWidget
operator|::
name|asViewport
parameter_list|()
block|{
comment|// Have a QGraphicsView with a QOpenGLWidget as its viewport.
name|QGraphicsScene
name|scene
decl_stmt|;
name|scene
operator|.
name|addItem
argument_list|(
operator|new
name|QGraphicsRectItem
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|)
expr_stmt|;
name|CountingGraphicsView
modifier|*
name|view
init|=
operator|new
name|CountingGraphicsView
decl_stmt|;
name|view
operator|->
name|setScene
argument_list|(
operator|&
name|scene
argument_list|)
expr_stmt|;
name|view
operator|->
name|setViewport
argument_list|(
operator|new
name|QOpenGLWidget
argument_list|)
expr_stmt|;
name|QWidget
name|widget
decl_stmt|;
name|QVBoxLayout
modifier|*
name|layout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|view
argument_list|)
expr_stmt|;
name|QPushButton
modifier|*
name|btn
init|=
operator|new
name|QPushButton
argument_list|(
literal|"Test"
argument_list|)
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|btn
argument_list|)
expr_stmt|;
name|widget
operator|.
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
name|widget
operator|.
name|show
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
operator|&
name|widget
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|view
operator|->
name|paintCount
argument_list|()
operator|>
literal|0
argument_list|)
expr_stmt|;
name|view
operator|->
name|resetPaintCount
argument_list|()
expr_stmt|;
comment|// And now trigger a repaint on the push button. We must not
comment|// receive paint events for the graphics view. If we do, that's a
comment|// side effect of QOpenGLWidget's special behavior and handling in
comment|// the widget stack.
name|btn
operator|->
name|update
argument_list|()
expr_stmt|;
name|qApp
operator|->
name|processEvents
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|view
operator|->
name|paintCount
argument_list|()
operator|==
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|PaintCountWidget
class|class
name|PaintCountWidget
super|:
specifier|public
name|QOpenGLWidget
block|{
public|public:
DECL|function|PaintCountWidget
name|PaintCountWidget
parameter_list|()
member_init_list|:
name|m_count
argument_list|(
literal|0
argument_list|)
block|{ }
DECL|function|reset
name|void
name|reset
parameter_list|()
block|{
name|m_count
operator|=
literal|0
expr_stmt|;
block|}
name|void
name|paintGL
parameter_list|()
name|Q_DECL_OVERRIDE
block|{
operator|++
name|m_count
expr_stmt|;
block|}
DECL|member|m_count
name|int
name|m_count
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|requestUpdate
name|void
name|tst_QOpenGLWidget
operator|::
name|requestUpdate
parameter_list|()
block|{
name|PaintCountWidget
name|w
decl_stmt|;
name|w
operator|.
name|resize
argument_list|(
literal|640
argument_list|,
literal|480
argument_list|)
expr_stmt|;
name|w
operator|.
name|show
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
operator|&
name|w
argument_list|)
expr_stmt|;
name|w
operator|.
name|reset
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|w
operator|.
name|m_count
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|w
operator|.
name|windowHandle
argument_list|()
operator|->
name|requestUpdate
argument_list|()
expr_stmt|;
name|QTRY_VERIFY
argument_list|(
name|w
operator|.
name|m_count
operator|>
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QOpenGLWidget
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qopenglwidget.moc"
end_include
end_unit
