begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtGlobal>
end_include
begin_include
include|#
directive|include
file|<QtAlgorithms>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPageSize>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_include
include|#
directive|include
file|<QtCore/qt_windows.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_OS_WIN
end_comment
begin_class
DECL|class|tst_QPageSize
class|class
name|tst_QPageSize
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|basics
parameter_list|()
function_decl|;
name|void
name|fuzzy
parameter_list|()
function_decl|;
name|void
name|custom
parameter_list|()
function_decl|;
name|void
name|statics
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|basics
name|void
name|tst_QPageSize
operator|::
name|basics
parameter_list|()
block|{
comment|// Invalid
name|QPageSize
name|invalid
init|=
name|QPageSize
argument_list|(
name|QPageSize
operator|::
name|Custom
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|invalid
operator|.
name|isValid
argument_list|()
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|invalid
operator|=
name|QPageSize
argument_list|(
name|QSize
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|invalid
operator|.
name|isValid
argument_list|()
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|invalid
operator|=
name|QPageSize
argument_list|(
name|QSizeF
argument_list|()
argument_list|,
name|QPageSize
operator|::
name|Millimeter
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|invalid
operator|.
name|isValid
argument_list|()
argument_list|,
literal|false
argument_list|)
expr_stmt|;
comment|// Simple QPageSize::PaperSizeId
name|QPageSize
name|a4
init|=
name|QPageSize
argument_list|(
name|QPageSize
operator|::
name|A4
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|a4
operator|.
name|isValid
argument_list|()
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|a4
operator|.
name|key
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"A4"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|a4
operator|.
name|name
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"A4"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|a4
operator|.
name|id
argument_list|()
argument_list|,
name|QPageSize
operator|::
name|A4
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|QCOMPARE
argument_list|(
name|a4
operator|.
name|windowsId
argument_list|()
argument_list|,
name|DMPAPER_A4
argument_list|)
expr_stmt|;
else|#
directive|else
name|QCOMPARE
argument_list|(
name|a4
operator|.
name|windowsId
argument_list|()
argument_list|,
literal|9
argument_list|)
expr_stmt|;
comment|// DMPAPER_A4
endif|#
directive|endif
name|QCOMPARE
argument_list|(
name|a4
operator|.
name|definitionSize
argument_list|()
argument_list|,
name|QSizeF
argument_list|(
literal|210
argument_list|,
literal|297
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|a4
operator|.
name|definitionUnits
argument_list|()
argument_list|,
name|QPageSize
operator|::
name|Millimeter
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|a4
operator|.
name|size
argument_list|(
name|QPageSize
operator|::
name|Millimeter
argument_list|)
argument_list|,
name|QSizeF
argument_list|(
literal|210
argument_list|,
literal|297
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|a4
operator|.
name|size
argument_list|(
name|QPageSize
operator|::
name|Inch
argument_list|)
argument_list|,
name|QSizeF
argument_list|(
literal|8.27
argument_list|,
literal|11.69
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|a4
operator|.
name|size
argument_list|(
name|QPageSize
operator|::
name|Pica
argument_list|)
argument_list|,
name|QSizeF
argument_list|(
literal|49.58
argument_list|,
literal|70.17
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|a4
operator|.
name|sizePoints
argument_list|()
argument_list|,
name|QSize
argument_list|(
literal|595
argument_list|,
literal|842
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|a4
operator|.
name|sizePixels
argument_list|(
literal|72
argument_list|)
argument_list|,
name|QSize
argument_list|(
literal|595
argument_list|,
literal|842
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|a4
operator|.
name|rect
argument_list|(
name|QPageSize
operator|::
name|Millimeter
argument_list|)
argument_list|,
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|210
argument_list|,
literal|297
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|a4
operator|.
name|rect
argument_list|(
name|QPageSize
operator|::
name|Inch
argument_list|)
argument_list|,
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|8.27
argument_list|,
literal|11.69
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|a4
operator|.
name|rect
argument_list|(
name|QPageSize
operator|::
name|Pica
argument_list|)
argument_list|,
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|49.58
argument_list|,
literal|70.17
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|a4
operator|.
name|rectPoints
argument_list|()
argument_list|,
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|595
argument_list|,
literal|842
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|a4
operator|.
name|rectPixels
argument_list|(
literal|72
argument_list|)
argument_list|,
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|595
argument_list|,
literal|842
argument_list|)
argument_list|)
expr_stmt|;
comment|// Simple QPageSize::PaperSizeId later in list
name|QPageSize
name|folio
init|=
name|QPageSize
argument_list|(
name|QPageSize
operator|::
name|Folio
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|folio
operator|.
name|isValid
argument_list|()
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|folio
operator|.
name|key
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"Folio"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|folio
operator|.
name|name
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"Folio (8.27 x 13 in)"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|folio
operator|.
name|id
argument_list|()
argument_list|,
name|QPageSize
operator|::
name|Folio
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|folio
operator|.
name|definitionSize
argument_list|()
argument_list|,
name|QSizeF
argument_list|(
literal|210
argument_list|,
literal|330
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|folio
operator|.
name|definitionUnits
argument_list|()
argument_list|,
name|QPageSize
operator|::
name|Millimeter
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|folio
operator|.
name|size
argument_list|(
name|QPageSize
operator|::
name|Millimeter
argument_list|)
argument_list|,
name|QSizeF
argument_list|(
literal|210
argument_list|,
literal|330
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|folio
operator|.
name|sizePoints
argument_list|()
argument_list|,
name|QSize
argument_list|(
literal|595
argument_list|,
literal|935
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|folio
operator|.
name|sizePixels
argument_list|(
literal|72
argument_list|)
argument_list|,
name|QSize
argument_list|(
literal|595
argument_list|,
literal|935
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|folio
operator|.
name|size
argument_list|(
name|QPageSize
operator|::
name|Inch
argument_list|)
argument_list|,
name|QSizeF
argument_list|(
literal|8.27
argument_list|,
literal|13
argument_list|)
argument_list|)
expr_stmt|;
comment|// Simple QPageSize::PaperSizeId last in list
name|QPageSize
name|you4
init|=
name|QPageSize
argument_list|(
name|QPageSize
operator|::
name|EnvelopeYou4
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|you4
operator|.
name|isValid
argument_list|()
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|you4
operator|.
name|key
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"EnvYou4"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|you4
operator|.
name|name
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"Envelope You 4"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|you4
operator|.
name|id
argument_list|()
argument_list|,
name|QPageSize
operator|::
name|EnvelopeYou4
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|QCOMPARE
argument_list|(
name|you4
operator|.
name|windowsId
argument_list|()
argument_list|,
name|DMPAPER_JENV_YOU4
argument_list|)
expr_stmt|;
else|#
directive|else
name|QCOMPARE
argument_list|(
name|you4
operator|.
name|windowsId
argument_list|()
argument_list|,
literal|91
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QCOMPARE
argument_list|(
name|you4
operator|.
name|size
argument_list|(
name|QPageSize
operator|::
name|Millimeter
argument_list|)
argument_list|,
name|QSizeF
argument_list|(
literal|105
argument_list|,
literal|235
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|you4
operator|.
name|size
argument_list|(
name|QPageSize
operator|::
name|Inch
argument_list|)
argument_list|,
name|QSizeF
argument_list|(
literal|4.13
argument_list|,
literal|9.25
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|you4
operator|.
name|sizePoints
argument_list|()
argument_list|,
name|QSize
argument_list|(
literal|298
argument_list|,
literal|666
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|you4
operator|.
name|sizePixels
argument_list|(
literal|72
argument_list|)
argument_list|,
name|QSize
argument_list|(
literal|298
argument_list|,
literal|666
argument_list|)
argument_list|)
expr_stmt|;
comment|// Simple QSize in Points
name|QPageSize
name|a4b
init|=
name|QPageSize
argument_list|(
name|QSize
argument_list|(
literal|595
argument_list|,
literal|842
argument_list|)
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|a4b
operator|.
name|isValid
argument_list|()
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|a4b
operator|.
name|id
argument_list|()
argument_list|,
name|QPageSize
operator|::
name|A4
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|a4b
operator|.
name|sizePoints
argument_list|()
argument_list|,
name|QSize
argument_list|(
literal|595
argument_list|,
literal|842
argument_list|)
argument_list|)
expr_stmt|;
comment|// Simple QSize in Points later in list, custom name
name|QPageSize
name|folio2
init|=
name|QPageSize
argument_list|(
name|QSize
argument_list|(
literal|595
argument_list|,
literal|935
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"Folio2"
argument_list|)
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|folio2
operator|.
name|isValid
argument_list|()
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|folio2
operator|.
name|name
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"Folio2"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|folio2
operator|.
name|id
argument_list|()
argument_list|,
name|QPageSize
operator|::
name|Folio
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|folio2
operator|.
name|sizePoints
argument_list|()
argument_list|,
name|QSize
argument_list|(
literal|595
argument_list|,
literal|935
argument_list|)
argument_list|)
expr_stmt|;
comment|// Comparisons
name|QCOMPARE
argument_list|(
operator|(
name|a4
operator|==
name|folio
operator|)
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|(
name|a4
operator|.
name|isEquivalentTo
argument_list|(
name|folio
argument_list|)
operator|)
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|(
name|a4
operator|==
name|a4b
operator|)
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|(
name|a4
operator|.
name|isEquivalentTo
argument_list|(
name|a4b
argument_list|)
operator|)
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|(
name|folio
operator|==
name|folio2
operator|)
argument_list|,
literal|false
argument_list|)
expr_stmt|;
comment|// Name different
name|QCOMPARE
argument_list|(
operator|(
name|folio
operator|.
name|isEquivalentTo
argument_list|(
name|folio2
argument_list|)
operator|)
argument_list|,
literal|true
argument_list|)
expr_stmt|;
comment|// Simple QSize in Millimeters
name|QPageSize
name|folio3
init|=
name|QPageSize
argument_list|(
name|QSizeF
argument_list|(
literal|210
argument_list|,
literal|330
argument_list|)
argument_list|,
name|QPageSize
operator|::
name|Millimeter
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|folio3
operator|.
name|isValid
argument_list|()
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|folio3
operator|.
name|id
argument_list|()
argument_list|,
name|QPageSize
operator|::
name|Folio
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|folio3
operator|.
name|sizePoints
argument_list|()
argument_list|,
name|QSize
argument_list|(
literal|595
argument_list|,
literal|935
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fuzzy
name|void
name|tst_QPageSize
operator|::
name|fuzzy
parameter_list|()
block|{
comment|// Using FuzzyMatch by default
comment|// Simple QSize within 3 Points
name|QPageSize
name|a4a
init|=
name|QPageSize
argument_list|(
name|QSize
argument_list|(
literal|592
argument_list|,
literal|845
argument_list|)
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|a4a
operator|.
name|isValid
argument_list|()
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|a4a
operator|.
name|id
argument_list|()
argument_list|,
name|QPageSize
operator|::
name|A4
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|a4a
operator|.
name|sizePoints
argument_list|()
argument_list|,
name|QSize
argument_list|(
literal|595
argument_list|,
literal|842
argument_list|)
argument_list|)
expr_stmt|;
comment|// Simple QSizeF within 1mm
name|QPageSize
name|a4b
init|=
name|QPageSize
argument_list|(
name|QSizeF
argument_list|(
literal|211
argument_list|,
literal|298
argument_list|)
argument_list|,
name|QPageSize
operator|::
name|Millimeter
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|a4b
operator|.
name|isValid
argument_list|()
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|a4b
operator|.
name|id
argument_list|()
argument_list|,
name|QPageSize
operator|::
name|A4
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|a4b
operator|.
name|size
argument_list|(
name|QPageSize
operator|::
name|Millimeter
argument_list|)
argument_list|,
name|QSizeF
argument_list|(
literal|210
argument_list|,
literal|297
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|a4b
operator|.
name|sizePoints
argument_list|()
argument_list|,
name|QSize
argument_list|(
literal|595
argument_list|,
literal|842
argument_list|)
argument_list|)
expr_stmt|;
comment|// Using FuzzyOrientationMatch
comment|// Exact A4 in landscape mode
name|QPageSize
name|a4l
init|=
name|QPageSize
argument_list|(
name|QSize
argument_list|(
literal|842
argument_list|,
literal|595
argument_list|)
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|a4l
operator|.
name|isValid
argument_list|()
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|a4l
operator|.
name|id
argument_list|()
argument_list|,
name|QPageSize
operator|::
name|Custom
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|a4l
operator|.
name|sizePoints
argument_list|()
argument_list|,
name|QSize
argument_list|(
literal|842
argument_list|,
literal|595
argument_list|)
argument_list|)
expr_stmt|;
name|a4l
operator|=
name|QPageSize
argument_list|(
name|QSize
argument_list|(
literal|842
argument_list|,
literal|595
argument_list|)
argument_list|,
name|QString
argument_list|()
argument_list|,
name|QPageSize
operator|::
name|FuzzyOrientationMatch
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|a4l
operator|.
name|isValid
argument_list|()
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|a4l
operator|.
name|id
argument_list|()
argument_list|,
name|QPageSize
operator|::
name|A4
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|a4l
operator|.
name|sizePoints
argument_list|()
argument_list|,
name|QSize
argument_list|(
literal|595
argument_list|,
literal|842
argument_list|)
argument_list|)
expr_stmt|;
comment|// Using ExactMatch
comment|// Simple QSize within 3 Points
name|QPageSize
name|a4d
init|=
name|QPageSize
argument_list|(
name|QSize
argument_list|(
literal|592
argument_list|,
literal|845
argument_list|)
argument_list|,
name|QString
argument_list|()
argument_list|,
name|QPageSize
operator|::
name|ExactMatch
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|a4d
operator|.
name|isValid
argument_list|()
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|a4d
operator|.
name|id
argument_list|()
argument_list|,
name|QPageSize
operator|::
name|Custom
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|a4d
operator|.
name|sizePoints
argument_list|()
argument_list|,
name|QSize
argument_list|(
literal|592
argument_list|,
literal|845
argument_list|)
argument_list|)
expr_stmt|;
comment|// Simple QSizeF within 1mm
name|QPageSize
name|a4e
init|=
name|QPageSize
argument_list|(
name|QSizeF
argument_list|(
literal|211
argument_list|,
literal|298
argument_list|)
argument_list|,
name|QPageSize
operator|::
name|Millimeter
argument_list|,
name|QString
argument_list|()
argument_list|,
name|QPageSize
operator|::
name|ExactMatch
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|a4e
operator|.
name|isValid
argument_list|()
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|a4e
operator|.
name|id
argument_list|()
argument_list|,
name|QPageSize
operator|::
name|Custom
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|a4e
operator|.
name|size
argument_list|(
name|QPageSize
operator|::
name|Millimeter
argument_list|)
argument_list|,
name|QSizeF
argument_list|(
literal|211
argument_list|,
literal|298
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|a4e
operator|.
name|sizePoints
argument_list|()
argument_list|,
name|QSize
argument_list|(
literal|598
argument_list|,
literal|845
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|custom
name|void
name|tst_QPageSize
operator|::
name|custom
parameter_list|()
block|{
comment|// Simple non-standard Points QSize
name|QPageSize
name|custom1
init|=
name|QPageSize
argument_list|(
name|QSize
argument_list|(
literal|500
argument_list|,
literal|600
argument_list|)
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|custom1
operator|.
name|isValid
argument_list|()
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|custom1
operator|.
name|key
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"Custom.500x600"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|custom1
operator|.
name|name
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"Custom (500pt x 600pt)"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|custom1
operator|.
name|id
argument_list|()
argument_list|,
name|QPageSize
operator|::
name|Custom
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|custom1
operator|.
name|definitionSize
argument_list|()
argument_list|,
name|QSizeF
argument_list|(
literal|500
argument_list|,
literal|600
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|custom1
operator|.
name|definitionUnits
argument_list|()
argument_list|,
name|QPageSize
operator|::
name|Point
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|custom1
operator|.
name|size
argument_list|(
name|QPageSize
operator|::
name|Millimeter
argument_list|)
argument_list|,
name|QSizeF
argument_list|(
literal|176.39
argument_list|,
literal|211.67
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|custom1
operator|.
name|size
argument_list|(
name|QPageSize
operator|::
name|Pica
argument_list|)
argument_list|,
name|QSizeF
argument_list|(
literal|41.67
argument_list|,
literal|50
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|custom1
operator|.
name|sizePoints
argument_list|()
argument_list|,
name|QSize
argument_list|(
literal|500
argument_list|,
literal|600
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|custom1
operator|.
name|sizePixels
argument_list|(
literal|72
argument_list|)
argument_list|,
name|QSize
argument_list|(
literal|500
argument_list|,
literal|600
argument_list|)
argument_list|)
expr_stmt|;
comment|// Simple non-standard MM QSizeF
name|QPageSize
name|custom2
init|=
name|QPageSize
argument_list|(
name|QSizeF
argument_list|(
literal|500.3
argument_list|,
literal|600.57
argument_list|)
argument_list|,
name|QPageSize
operator|::
name|Millimeter
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|custom2
operator|.
name|isValid
argument_list|()
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|custom2
operator|.
name|key
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"Custom.500.3x600.57mm"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|custom2
operator|.
name|name
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"Custom (500.3mm x 600.57mm)"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|custom2
operator|.
name|id
argument_list|()
argument_list|,
name|QPageSize
operator|::
name|Custom
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|custom2
operator|.
name|definitionSize
argument_list|()
argument_list|,
name|QSizeF
argument_list|(
literal|500.3
argument_list|,
literal|600.57
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|custom2
operator|.
name|definitionUnits
argument_list|()
argument_list|,
name|QPageSize
operator|::
name|Millimeter
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|custom2
operator|.
name|size
argument_list|(
name|QPageSize
operator|::
name|Millimeter
argument_list|)
argument_list|,
name|QSizeF
argument_list|(
literal|500.3
argument_list|,
literal|600.57
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|custom2
operator|.
name|size
argument_list|(
name|QPageSize
operator|::
name|Pica
argument_list|)
argument_list|,
name|QSizeF
argument_list|(
literal|118.18
argument_list|,
literal|141.87
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|custom2
operator|.
name|sizePoints
argument_list|()
argument_list|,
name|QSize
argument_list|(
literal|1418
argument_list|,
literal|1702
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|custom2
operator|.
name|sizePixels
argument_list|(
literal|72
argument_list|)
argument_list|,
name|QSize
argument_list|(
literal|1418
argument_list|,
literal|1702
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|statics
name|void
name|tst_QPageSize
operator|::
name|statics
parameter_list|()
block|{
name|QCOMPARE
argument_list|(
name|QPageSize
operator|::
name|key
argument_list|(
name|QPageSize
operator|::
name|EnvelopeYou4
argument_list|)
argument_list|,
name|QString
argument_list|(
literal|"EnvYou4"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QPageSize
operator|::
name|name
argument_list|(
name|QPageSize
operator|::
name|EnvelopeYou4
argument_list|)
argument_list|,
name|QString
argument_list|(
literal|"Envelope You 4"
argument_list|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|QCOMPARE
argument_list|(
name|QPageSize
operator|::
name|windowsId
argument_list|(
name|QPageSize
operator|::
name|EnvelopeYou4
argument_list|)
argument_list|,
name|DMPAPER_JENV_YOU4
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QPageSize
operator|::
name|id
argument_list|(
name|DMPAPER_JENV_YOU4
argument_list|)
argument_list|,
name|QPageSize
operator|::
name|EnvelopeYou4
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QPageSize
operator|::
name|id
argument_list|(
name|DMPAPER_A4_ROTATED
argument_list|)
argument_list|,
name|QPageSize
operator|::
name|A4
argument_list|)
expr_stmt|;
else|#
directive|else
name|QCOMPARE
argument_list|(
name|QPageSize
operator|::
name|windowsId
argument_list|(
name|QPageSize
operator|::
name|EnvelopeYou4
argument_list|)
argument_list|,
literal|91
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QPageSize
operator|::
name|id
argument_list|(
literal|91
argument_list|)
argument_list|,
name|QPageSize
operator|::
name|EnvelopeYou4
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QPageSize
operator|::
name|id
argument_list|(
literal|77
argument_list|)
argument_list|,
name|QPageSize
operator|::
name|A4
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QCOMPARE
argument_list|(
name|QPageSize
operator|::
name|id
argument_list|(
name|QSize
argument_list|(
literal|298
argument_list|,
literal|666
argument_list|)
argument_list|)
argument_list|,
name|QPageSize
operator|::
name|EnvelopeYou4
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QPageSize
operator|::
name|id
argument_list|(
name|QSizeF
argument_list|(
literal|105
argument_list|,
literal|235
argument_list|)
argument_list|,
name|QPageSize
operator|::
name|Millimeter
argument_list|)
argument_list|,
name|QPageSize
operator|::
name|EnvelopeYou4
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QPageSize
operator|::
name|definitionSize
argument_list|(
name|QPageSize
operator|::
name|Letter
argument_list|)
argument_list|,
name|QSizeF
argument_list|(
literal|8.5
argument_list|,
literal|11
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QPageSize
operator|::
name|definitionUnits
argument_list|(
name|QPageSize
operator|::
name|Letter
argument_list|)
argument_list|,
name|QPageSize
operator|::
name|Inch
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QPageSize
operator|::
name|definitionSize
argument_list|(
name|QPageSize
operator|::
name|EnvelopeYou4
argument_list|)
argument_list|,
name|QSizeF
argument_list|(
literal|105
argument_list|,
literal|235
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QPageSize
operator|::
name|definitionUnits
argument_list|(
name|QPageSize
operator|::
name|EnvelopeYou4
argument_list|)
argument_list|,
name|QPageSize
operator|::
name|Millimeter
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QPageSize
operator|::
name|size
argument_list|(
name|QPageSize
operator|::
name|EnvelopeYou4
argument_list|,
name|QPageSize
operator|::
name|Millimeter
argument_list|)
argument_list|,
name|QSizeF
argument_list|(
literal|105
argument_list|,
literal|235
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QPageSize
operator|::
name|sizePoints
argument_list|(
name|QPageSize
operator|::
name|EnvelopeYou4
argument_list|)
argument_list|,
name|QSize
argument_list|(
literal|298
argument_list|,
literal|666
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QPageSize
operator|::
name|sizePixels
argument_list|(
name|QPageSize
operator|::
name|EnvelopeYou4
argument_list|,
literal|72
argument_list|)
argument_list|,
name|QSize
argument_list|(
literal|298
argument_list|,
literal|666
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_APPLESS_MAIN
argument_list|(
argument|tst_QPageSize
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qpagesize.moc"
end_include
end_unit