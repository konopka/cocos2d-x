#ifndef __TABLEVIEWTESTSCENE_H__
#define __TABLEVIEWTESTSCENE_H__

#include <sys/types.h>                  // for ssize_t
#include "2d/CCLayer.h"                 // for Layer
#include "platform/CCPlatformMacros.h" // for CREATE_FUNC
#include "GUI/CCScrollView/CCTableView.h"  // for TableView (ptr only), etc
#include "GUI/CCScrollView/CCTableViewCell.h"  // for TableViewCell
#include "math/CCGeometry.h"            // for Size
namespace cocos2d { class Ref; }
namespace cocos2d { namespace extension { class ScrollView; } }

void runTableViewTest();

class TableViewTestLayer : public cocos2d::Layer, public cocos2d::extension::TableViewDataSource, public cocos2d::extension::TableViewDelegate
{
public:
    virtual bool init() override;  
   
	void toExtensionsMainLayer(cocos2d::Ref *sender);

    CREATE_FUNC(TableViewTestLayer);
    
    virtual void scrollViewDidScroll(cocos2d::extension::ScrollView* view) {};
    virtual void scrollViewDidZoom(cocos2d::extension::ScrollView* view) {}
    virtual void tableCellTouched(cocos2d::extension::TableView* table, cocos2d::extension::TableViewCell* cell);
    virtual cocos2d::Size tableCellSizeForIndex(cocos2d::extension::TableView *table, ssize_t idx);
    virtual cocos2d::extension::TableViewCell* tableCellAtIndex(cocos2d::extension::TableView *table, ssize_t idx);
    virtual ssize_t numberOfCellsInTableView(cocos2d::extension::TableView *table);
};

#endif // __TABLEVIEWTESTSCENE_H__
