/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SampleCode.h"
#include "SkView.h"
#include "SkCanvas.h"
#include "SkDevice.h"
#include "SkColorPriv.h"
#include "SkShader.h"
#include "CanvasRenderingContext2D.h"
#include "SkBlurMaskFilter.h"
#include "SkGradientShader.h"

using namespace WebCore;
using namespace WTF;

class FontView : public SampleView
{
    SkPaint fBGPaint;
public:
	FontView() 
	{
		int i = 0;
		i++;
    }

protected:
    // overrides from SkEventSink
    virtual bool onQuery(SkEvent* evt)
	{
        if (SampleCode::TitleQ(*evt)) 
		{
            SampleCode::TitleR(evt, "FontView");
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

    virtual void onDrawContent(SkCanvas* canvas)
	{
		PassOwnPtr<CanvasRenderingContext2D> ctx = CanvasRenderingContext2D::create(canvas, NULL, false);
		ctx->setFont("italic small-caps bold 40px sans-serif");
		String str = "HelloWorld";
		ctx->strokeText(str, 10, 50);
		return;
		//ctx->strokeText("Hello world", 10, 50);
		SkPaint paint;
		////paint.setAntiAlias(true);
		paint.setColor(0xffff0000);
		paint.setTextSize(40);
		paint.setStyle(SkPaint::kFill_Style);
		//SkPoint p = SkPoint::Make(50, 50);
		//SkPoint q = SkPoint::Make(100, 50);
		//SkPoint pts[] = { p, q };
		//SkScalar t, temp, x, y;
		//SkColor colors[] = {
		//	SK_ColorRED, SK_ColorGREEN, SK_ColorBLUE, SK_ColorWHITE, SK_ColorBLACK
		//};
		////�졢�̡������ס��ڣ���Щ���alphaֵ����FF������͸��
		//SkShader *shader;
		//shader = SkGradientShader::CreateLinear(
		//	pts, colors, NULL, SK_ARRAY_COUNT(colors), SkShader::kMirror_TileMode);		canvas->drawText("test", 4, 100, 100, paint);
		//paint.setShader(shader);
		//shader->unref();
		//paint.setTextAlign(SkPaint::kCenter_Align);
		canvas->drawText("", 4, 100, 100, paint);
		return;
	}

private:
    typedef SampleView INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new FontView; }
static SkViewRegister reg(MyFactory);
