#ifndef __CUSTOMTABELVIEWCELL_H__
#define __CUSTOMTABELVIEWCELL_H__

#include <stdint.h>                     // for uint32_t
#include "GUI/CCScrollView/CCTableViewCell.h"  // for TableViewCell
#include "math/Mat4.h"                  // for Mat4
namespace cocos2d { class Renderer; }

class CustomTableViewCell : public cocos2d::extension::TableViewCell
{
public:
	virtual void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags) override;
};

#endif /* __CUSTOMTABELVIEWCELL_H__ */

