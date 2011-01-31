//
//  Copyright 2011 Andrey Tarantsov. Distributed under the MIT license.
//

#import <Foundation/Foundation.h>

@protocol ATArrayViewDelegate;

// A container that arranges its items in rows and columns similar to the
// thumbnails screen in Photos.app, the API is modeled after UITableView.
@interface ATArrayView : UIView {
	// subviews
	UIScrollView *_scrollView;

	// properties
	id<ATArrayViewDelegate> _delegate;

	UIEdgeInsets    _contentInsets;
	CGSize          _itemSize;
	CGFloat         _minimumColumnGap;

	// state
	NSInteger       _itemCount;
	NSMutableSet   *_recycledItems;
	NSMutableSet   *_visibleItems;

	// geometry
	NSInteger       _colCount;
	NSInteger       _rowCount;
	CGFloat         _rowGap;
	CGFloat         _colGap;
	UIEdgeInsets    _effectiveInsets;
}

@property(nonatomic, assign) id<ATArrayViewDelegate> delegate;

@property(nonatomic, assign) UIEdgeInsets contentInsets;

@property(nonatomic, assign) CGSize itemSize;

@property(nonatomic, assign) CGFloat minimumColumnGap;

@property(nonatomic, readonly) NSInteger itemCount;

@property(nonatomic, readonly) NSInteger firstVisibleItemIndex;

@property(nonatomic, readonly) NSInteger lastVisibleItemIndex;

- (void)reloadData;  // must be called at least once to display something

- (UIView *)viewForItemAtIndex:(NSUInteger)index;  // nil if not loaded

- (UIView *)dequeueReusableItem;  // nil if none

- (CGRect)rectForItemAtIndex:(NSUInteger)index;

@end


@protocol ATArrayViewDelegate <NSObject>

@required

- (NSInteger)numberOfItemsInArrayView:(ATArrayView *)arrayView;

- (UIView *)viewForItemInArrayView:(ATArrayView *)arrayView atIndex:(NSInteger)index;

@end


@interface ATArrayViewController : UIViewController <ATArrayViewDelegate> {
}

@property(nonatomic, readonly) ATArrayView *arrayView;

@end
