begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"mainwindow.h"
end_include
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<QPainterPath>
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_include
include|#
directive|include
file|<QMap>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_function
DECL|function|render_qt_text
name|void
name|render_qt_text
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|,
specifier|const
name|QColor
modifier|&
name|color
parameter_list|)
block|{
name|QPainterPath
name|path
decl_stmt|;
name|path
operator|.
name|moveTo
argument_list|(
operator|-
literal|0.083695
argument_list|,
literal|0.283849
argument_list|)
expr_stmt|;
name|path
operator|.
name|cubicTo
argument_list|(
operator|-
literal|0.049581
argument_list|,
literal|0.349613
argument_list|,
operator|-
literal|0.012720
argument_list|,
literal|0.397969
argument_list|,
literal|0.026886
argument_list|,
literal|0.428917
argument_list|)
expr_stmt|;
name|path
operator|.
name|cubicTo
argument_list|(
literal|0.066493
argument_list|,
literal|0.459865
argument_list|,
literal|0.111593
argument_list|,
literal|0.477595
argument_list|,
literal|0.162186
argument_list|,
literal|0.482108
argument_list|)
expr_stmt|;
name|path
operator|.
name|lineTo
argument_list|(
literal|0.162186
argument_list|,
literal|0.500000
argument_list|)
expr_stmt|;
name|path
operator|.
name|cubicTo
argument_list|(
literal|0.115929
argument_list|,
literal|0.498066
argument_list|,
literal|0.066565
argument_list|,
literal|0.487669
argument_list|,
literal|0.014094
argument_list|,
literal|0.468810
argument_list|)
expr_stmt|;
name|path
operator|.
name|cubicTo
argument_list|(
operator|-
literal|0.038378
argument_list|,
literal|0.449952
argument_list|,
operator|-
literal|0.088103
argument_list|,
literal|0.423839
argument_list|,
operator|-
literal|0.135082
argument_list|,
literal|0.390474
argument_list|)
expr_stmt|;
name|path
operator|.
name|cubicTo
argument_list|(
operator|-
literal|0.182061
argument_list|,
literal|0.357108
argument_list|,
operator|-
literal|0.222608
argument_list|,
literal|0.321567
argument_list|,
operator|-
literal|0.256722
argument_list|,
literal|0.283849
argument_list|)
expr_stmt|;
name|path
operator|.
name|cubicTo
argument_list|(
operator|-
literal|0.304712
argument_list|,
literal|0.262250
argument_list|,
operator|-
literal|0.342874
argument_list|,
literal|0.239362
argument_list|,
operator|-
literal|0.371206
argument_list|,
literal|0.215184
argument_list|)
expr_stmt|;
name|path
operator|.
name|cubicTo
argument_list|(
operator|-
literal|0.411969
argument_list|,
literal|0.179078
argument_list|,
operator|-
literal|0.443625
argument_list|,
literal|0.134671
argument_list|,
operator|-
literal|0.466175
argument_list|,
literal|0.081963
argument_list|)
expr_stmt|;
name|path
operator|.
name|cubicTo
argument_list|(
operator|-
literal|0.488725
argument_list|,
literal|0.029255
argument_list|,
operator|-
literal|0.500000
argument_list|,
operator|-
literal|0.033043
argument_list|,
operator|-
literal|0.500000
argument_list|,
operator|-
literal|0.104932
argument_list|)
expr_stmt|;
name|path
operator|.
name|cubicTo
argument_list|(
operator|-
literal|0.500000
argument_list|,
operator|-
literal|0.218407
argument_list|,
operator|-
literal|0.467042
argument_list|,
operator|-
literal|0.312621
argument_list|,
operator|-
literal|0.401127
argument_list|,
operator|-
literal|0.387573
argument_list|)
expr_stmt|;
name|path
operator|.
name|cubicTo
argument_list|(
operator|-
literal|0.335212
argument_list|,
operator|-
literal|0.462524
argument_list|,
operator|-
literal|0.255421
argument_list|,
operator|-
literal|0.500000
argument_list|,
operator|-
literal|0.161752
argument_list|,
operator|-
literal|0.500000
argument_list|)
expr_stmt|;
name|path
operator|.
name|cubicTo
argument_list|(
operator|-
literal|0.072998
argument_list|,
operator|-
literal|0.500000
argument_list|,
literal|0.003903
argument_list|,
operator|-
literal|0.462444
argument_list|,
literal|0.068951
argument_list|,
operator|-
literal|0.387331
argument_list|)
expr_stmt|;
name|path
operator|.
name|cubicTo
argument_list|(
literal|0.133998
argument_list|,
operator|-
literal|0.312218
argument_list|,
literal|0.166522
argument_list|,
operator|-
literal|0.217440
argument_list|,
literal|0.166522
argument_list|,
operator|-
literal|0.102998
argument_list|)
expr_stmt|;
name|path
operator|.
name|cubicTo
argument_list|(
literal|0.166522
argument_list|,
operator|-
literal|0.010155
argument_list|,
literal|0.143394
argument_list|,
literal|0.071325
argument_list|,
literal|0.097138
argument_list|,
literal|0.141441
argument_list|)
expr_stmt|;
name|path
operator|.
name|cubicTo
argument_list|(
literal|0.050882
argument_list|,
literal|0.211557
argument_list|,
operator|-
literal|0.009396
argument_list|,
literal|0.259026
argument_list|,
operator|-
literal|0.083695
argument_list|,
literal|0.283849
argument_list|)
expr_stmt|;
name|path
operator|.
name|moveTo
argument_list|(
operator|-
literal|0.167823
argument_list|,
operator|-
literal|0.456963
argument_list|)
expr_stmt|;
name|path
operator|.
name|cubicTo
argument_list|(
operator|-
literal|0.228823
argument_list|,
operator|-
literal|0.456963
argument_list|,
operator|-
literal|0.277826
argument_list|,
operator|-
literal|0.432624
argument_list|,
operator|-
literal|0.314831
argument_list|,
operator|-
literal|0.383946
argument_list|)
expr_stmt|;
name|path
operator|.
name|cubicTo
argument_list|(
operator|-
literal|0.361665
argument_list|,
operator|-
literal|0.323340
argument_list|,
operator|-
literal|0.385082
argument_list|,
operator|-
literal|0.230335
argument_list|,
operator|-
literal|0.385082
argument_list|,
operator|-
literal|0.104932
argument_list|)
expr_stmt|;
name|path
operator|.
name|cubicTo
argument_list|(
operator|-
literal|0.385082
argument_list|,
literal|0.017569
argument_list|,
operator|-
literal|0.361376
argument_list|,
literal|0.112025
argument_list|,
operator|-
literal|0.313964
argument_list|,
literal|0.178433
argument_list|)
expr_stmt|;
name|path
operator|.
name|cubicTo
argument_list|(
operator|-
literal|0.277248
argument_list|,
literal|0.229368
argument_list|,
operator|-
literal|0.228534
argument_list|,
literal|0.254836
argument_list|,
operator|-
literal|0.167823
argument_list|,
literal|0.254836
argument_list|)
expr_stmt|;
name|path
operator|.
name|cubicTo
argument_list|(
operator|-
literal|0.105088
argument_list|,
literal|0.254836
argument_list|,
operator|-
literal|0.054496
argument_list|,
literal|0.229368
argument_list|,
operator|-
literal|0.016045
argument_list|,
literal|0.178433
argument_list|)
expr_stmt|;
name|path
operator|.
name|cubicTo
argument_list|(
literal|0.029055
argument_list|,
literal|0.117827
argument_list|,
literal|0.051605
argument_list|,
literal|0.028691
argument_list|,
literal|0.051605
argument_list|,
operator|-
literal|0.088975
argument_list|)
expr_stmt|;
name|path
operator|.
name|cubicTo
argument_list|(
literal|0.051605
argument_list|,
operator|-
literal|0.179562
argument_list|,
literal|0.039318
argument_list|,
operator|-
literal|0.255803
argument_list|,
literal|0.014744
argument_list|,
operator|-
literal|0.317698
argument_list|)
expr_stmt|;
name|path
operator|.
name|cubicTo
argument_list|(
operator|-
literal|0.004337
argument_list|,
operator|-
literal|0.365409
argument_list|,
operator|-
literal|0.029705
argument_list|,
operator|-
literal|0.400548
argument_list|,
operator|-
literal|0.061362
argument_list|,
operator|-
literal|0.423114
argument_list|)
expr_stmt|;
name|path
operator|.
name|cubicTo
argument_list|(
operator|-
literal|0.093018
argument_list|,
operator|-
literal|0.445680
argument_list|,
operator|-
literal|0.128505
argument_list|,
operator|-
literal|0.456963
argument_list|,
operator|-
literal|0.167823
argument_list|,
operator|-
literal|0.456963
argument_list|)
expr_stmt|;
name|path
operator|.
name|moveTo
argument_list|(
literal|0.379011
argument_list|,
operator|-
literal|0.404739
argument_list|)
expr_stmt|;
name|path
operator|.
name|lineTo
argument_list|(
literal|0.379011
argument_list|,
operator|-
literal|0.236460
argument_list|)
expr_stmt|;
name|path
operator|.
name|lineTo
argument_list|(
literal|0.486123
argument_list|,
operator|-
literal|0.236460
argument_list|)
expr_stmt|;
name|path
operator|.
name|lineTo
argument_list|(
literal|0.486123
argument_list|,
operator|-
literal|0.197292
argument_list|)
expr_stmt|;
name|path
operator|.
name|lineTo
argument_list|(
literal|0.379011
argument_list|,
operator|-
literal|0.197292
argument_list|)
expr_stmt|;
name|path
operator|.
name|lineTo
argument_list|(
literal|0.379011
argument_list|,
literal|0.134913
argument_list|)
expr_stmt|;
name|path
operator|.
name|cubicTo
argument_list|(
literal|0.379011
argument_list|,
literal|0.168117
argument_list|,
literal|0.383276
argument_list|,
literal|0.190442
argument_list|,
literal|0.391804
argument_list|,
literal|0.201886
argument_list|)
expr_stmt|;
name|path
operator|.
name|cubicTo
argument_list|(
literal|0.400332
argument_list|,
literal|0.213330
argument_list|,
literal|0.411246
argument_list|,
literal|0.219052
argument_list|,
literal|0.424545
argument_list|,
literal|0.219052
argument_list|)
expr_stmt|;
name|path
operator|.
name|cubicTo
argument_list|(
literal|0.435531
argument_list|,
literal|0.219052
argument_list|,
literal|0.446227
argument_list|,
literal|0.215264
argument_list|,
literal|0.456635
argument_list|,
literal|0.207689
argument_list|)
expr_stmt|;
name|path
operator|.
name|cubicTo
argument_list|(
literal|0.467042
argument_list|,
literal|0.200113
argument_list|,
literal|0.474993
argument_list|,
literal|0.188910
argument_list|,
literal|0.480486
argument_list|,
literal|0.174081
argument_list|)
expr_stmt|;
name|path
operator|.
name|lineTo
argument_list|(
literal|0.500000
argument_list|,
literal|0.174081
argument_list|)
expr_stmt|;
name|path
operator|.
name|cubicTo
argument_list|(
literal|0.488436
argument_list|,
literal|0.210509
argument_list|,
literal|0.471957
argument_list|,
literal|0.237911
argument_list|,
literal|0.450564
argument_list|,
literal|0.256286
argument_list|)
expr_stmt|;
name|path
operator|.
name|cubicTo
argument_list|(
literal|0.429170
argument_list|,
literal|0.274662
argument_list|,
literal|0.407054
argument_list|,
literal|0.283849
argument_list|,
literal|0.384215
argument_list|,
literal|0.283849
argument_list|)
expr_stmt|;
name|path
operator|.
name|cubicTo
argument_list|(
literal|0.368893
argument_list|,
literal|0.283849
argument_list|,
literal|0.353859
argument_list|,
literal|0.279094
argument_list|,
literal|0.339115
argument_list|,
literal|0.269584
argument_list|)
expr_stmt|;
name|path
operator|.
name|cubicTo
argument_list|(
literal|0.324371
argument_list|,
literal|0.260074
argument_list|,
literal|0.313530
argument_list|,
literal|0.246534
argument_list|,
literal|0.306592
argument_list|,
literal|0.228965
argument_list|)
expr_stmt|;
name|path
operator|.
name|cubicTo
argument_list|(
literal|0.299653
argument_list|,
literal|0.211396
argument_list|,
literal|0.296184
argument_list|,
literal|0.184075
argument_list|,
literal|0.296184
argument_list|,
literal|0.147002
argument_list|)
expr_stmt|;
name|path
operator|.
name|lineTo
argument_list|(
literal|0.296184
argument_list|,
operator|-
literal|0.197292
argument_list|)
expr_stmt|;
name|path
operator|.
name|lineTo
argument_list|(
literal|0.223330
argument_list|,
operator|-
literal|0.197292
argument_list|)
expr_stmt|;
name|path
operator|.
name|lineTo
argument_list|(
literal|0.223330
argument_list|,
operator|-
literal|0.215667
argument_list|)
expr_stmt|;
name|path
operator|.
name|cubicTo
argument_list|(
literal|0.241833
argument_list|,
operator|-
literal|0.224049
argument_list|,
literal|0.260697
argument_list|,
operator|-
literal|0.237992
argument_list|,
literal|0.279922
argument_list|,
operator|-
literal|0.257495
argument_list|)
expr_stmt|;
name|path
operator|.
name|cubicTo
argument_list|(
literal|0.299147
argument_list|,
operator|-
literal|0.276999
argument_list|,
literal|0.316276
argument_list|,
operator|-
literal|0.300129
argument_list|,
literal|0.331310
argument_list|,
operator|-
literal|0.326886
argument_list|)
expr_stmt|;
name|path
operator|.
name|cubicTo
argument_list|(
literal|0.338826
argument_list|,
operator|-
literal|0.341070
argument_list|,
literal|0.349523
argument_list|,
operator|-
literal|0.367021
argument_list|,
literal|0.363400
argument_list|,
operator|-
literal|0.404739
argument_list|)
expr_stmt|;
name|path
operator|.
name|lineTo
argument_list|(
literal|0.379011
argument_list|,
operator|-
literal|0.404739
argument_list|)
expr_stmt|;
name|path
operator|.
name|moveTo
argument_list|(
operator|-
literal|0.535993
argument_list|,
literal|0.275629
argument_list|)
expr_stmt|;
name|painter
operator|->
name|translate
argument_list|(
name|w
operator|/
literal|2
argument_list|,
name|h
operator|/
literal|2
argument_list|)
expr_stmt|;
name|double
name|scale
init|=
name|qMin
argument_list|(
name|w
argument_list|,
name|h
argument_list|)
operator|*
literal|8
operator|/
literal|10.0
decl_stmt|;
name|painter
operator|->
name|scale
argument_list|(
name|scale
argument_list|,
name|scale
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|Antialiasing
argument_list|)
expr_stmt|;
name|painter
operator|->
name|save
argument_list|()
expr_stmt|;
name|painter
operator|->
name|translate
argument_list|(
literal|.1
argument_list|,
literal|.1
argument_list|)
expr_stmt|;
name|painter
operator|->
name|fillPath
argument_list|(
name|path
argument_list|,
name|QColor
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|63
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|->
name|restore
argument_list|()
expr_stmt|;
name|painter
operator|->
name|setBrush
argument_list|(
name|color
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setPen
argument_list|(
name|QPen
argument_list|(
name|Qt
operator|::
name|black
argument_list|,
literal|0.02
argument_list|,
name|Qt
operator|::
name|SolidLine
argument_list|,
name|Qt
operator|::
name|FlatCap
argument_list|,
name|Qt
operator|::
name|RoundJoin
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawPath
argument_list|(
name|path
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|usage
name|void
name|usage
parameter_list|()
block|{
name|qWarning
argument_list|()
operator|<<
literal|"Usage: mainwindow [-SizeHint<color><width>x<height>] ..."
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|parseCustomSizeHints
name|QMap
argument_list|<
name|QString
argument_list|,
name|QSize
argument_list|>
name|parseCustomSizeHints
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|QMap
argument_list|<
name|QString
argument_list|,
name|QSize
argument_list|>
name|result
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
name|argc
condition|;
operator|++
name|i
control|)
block|{
name|QString
name|arg
init|=
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|argv
index|[
name|i
index|]
argument_list|)
decl_stmt|;
if|if
condition|(
name|arg
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"-SizeHint"
argument_list|)
argument_list|)
condition|)
block|{
name|QString
name|name
init|=
name|arg
operator|.
name|mid
argument_list|(
literal|9
argument_list|)
decl_stmt|;
if|if
condition|(
name|name
operator|.
name|isEmpty
argument_list|()
condition|)
name|usage
argument_list|()
expr_stmt|;
if|if
condition|(
operator|++
name|i
operator|==
name|argc
condition|)
name|usage
argument_list|()
expr_stmt|;
name|QString
name|sizeStr
init|=
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|argv
index|[
name|i
index|]
argument_list|)
decl_stmt|;
name|int
name|idx
init|=
name|sizeStr
operator|.
name|indexOf
argument_list|(
name|QLatin1Char
argument_list|(
literal|'x'
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|idx
operator|==
operator|-
literal|1
condition|)
name|usage
argument_list|()
expr_stmt|;
name|bool
name|ok
decl_stmt|;
name|int
name|w
init|=
name|sizeStr
operator|.
name|left
argument_list|(
name|idx
argument_list|)
operator|.
name|toInt
argument_list|(
operator|&
name|ok
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
name|usage
argument_list|()
expr_stmt|;
name|int
name|h
init|=
name|sizeStr
operator|.
name|mid
argument_list|(
name|idx
operator|+
literal|1
argument_list|)
operator|.
name|toInt
argument_list|(
operator|&
name|ok
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
name|usage
argument_list|()
expr_stmt|;
name|result
index|[
name|name
index|]
operator|=
name|QSize
argument_list|(
name|w
argument_list|,
name|h
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|QApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|QMap
argument_list|<
name|QString
argument_list|,
name|QSize
argument_list|>
name|customSizeHints
init|=
name|parseCustomSizeHints
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|MainWindow
name|mainWin
argument_list|(
name|customSizeHints
argument_list|)
decl_stmt|;
name|mainWin
operator|.
name|resize
argument_list|(
literal|800
argument_list|,
literal|600
argument_list|)
expr_stmt|;
name|mainWin
operator|.
name|show
argument_list|()
expr_stmt|;
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
end_unit
