//
//  QGraphicNode.mm
//  QMediaSDK
//
//  Created by spring on 20/05/2017.
//  Copyright © 2017 QMedia. All rights reserved.
//

#import "QGraphicNode_internal.h"

using GraphicCore::AnimaNode;

@interface QNodeAnimator(internal)
@property (nonatomic, readonly) AnimaNode::Animator* native;
@end

QColor4 QColorMaker(float r, float g, float b, float a) {
    QColor4 color4;
    color4.r = r; color4.g = g; color4.b = b; color4.a = a;
    return color4;
}

#pragma mark QGraphicNode

@implementation QGraphicNode {
    NSString *_nodeName;
    GraphicCore::RenderNodeRef _graphicNode;
    NSMutableArray* _childrens;
    NSMutableArray* _animators;
}

@synthesize parent = _parent;

- (instancetype)init{
    if ((self = [super init]) != nil) {
        self.origin_renderRange = NSMakeRange(0, 0);
        self.origin_visible = false;
//        self.origin_rotation = 0;
        self.origin_rotation3d = QVectorV3(0, 0, 0);
        self.origin_scaleX = 1.0f;
        self.origin_scaleY = 1.0f;
        self.origin_scaleZ = 1.0f;
        self.origin_contentSize = CGSizeMake(0, 0);
        self.origin_position = CGPointMake(0, 0);
        self.origin_positionZ = 0;
        self.origin_anchorPoint = CGPointMake(0, 0);
        self.origin_color4 = QColorMaker(1, 1, 1, 1);
        self.origin_alpha = 1.0f;
        self.origin_visible = true;
    }
    return self;
}

- (instancetype)initWithName:(NSString*)name
{
    if ((self = [self init]) != nil) {
        _graphicNode = GraphicCore::RenderNodeRef(new GraphicCore::RenderNode());
        _nodeName = [name copy];
        std::string s_name = std::string([name UTF8String]);
        _graphicNode->setName(s_name);
        _childrens = [[NSMutableArray alloc] init];
        _animators = [[NSMutableArray alloc] init];
        _parent = nil;
    }
    return self;
}

#pragma mark - private function
- (instancetype)initWithNode:(GraphicCore::RenderNodeRef)graphicNode
{
    if ((self = [self init]) != nil) {
        _graphicNode = graphicNode;
        if (_graphicNode == nullptr) {
            return nil;
        }
        _nodeName = [NSString stringWithUTF8String:graphicNode->getName().c_str()];
        _childrens = [[NSMutableArray alloc] init];
        _animators = [[NSMutableArray alloc] init];
        _parent = nil;
    }
    return self;
}

- (GraphicCore::RenderNodeRef)native {
    return _graphicNode;
}
#pragma mark - private function //

- (void)setParent:(QGraphicNode *)parent {
    _parent = parent;
}

- (NSArray*)childrens{
    return _childrens;
}

- (bool)addChildNode:(QGraphicNode*)childNode
{
    if (childNode == nil) {
        return false;
    }
    if([_childrens containsObject:childNode])
        return true;
    childNode.native->removeFromParent();
    childNode.native->setParent(nullptr);
    if(_graphicNode->addChildren(childNode.native.get())){
        [_childrens addObject:childNode];
        [childNode setParent:self];
        return true;
    }
    return false;
}
- (bool)removeChildNode:(QGraphicNode*)childNode
{
    if([_childrens containsObject:childNode])
    {
        childNode.native->removeFromParent();
        childNode.native->setParent(nullptr);
        [_childrens removeObject:childNode];
        return true;
    }
    return false;
}

- (bool)addChildNodeDirect:(QGraphicNode*)childNode {
    if (childNode != nil && ![_childrens containsObject:childNode]) {
        [_childrens addObject:childNode];
        [childNode setParent:self];
        return true;
    }
    return false;
}

- (bool)removeChildNodeDirect:(QGraphicNode*)childNode {
    if([_childrens containsObject:childNode])
    {
        [childNode setParent:nil];
        [_childrens removeObject:childNode];
        return true;
    }
    return false;
}

- (void)clearAllChildrens
{
    for (QGraphicNode* child in _childrens) {
        child.native->removeFromParent();
        child.native->setParent(nullptr);
    }
    [_childrens removeAllObjects];
}

- (NSArray*)animators{
    return _animators;
}

- (bool)addAnimator:(QNodeAnimator*)animator {
    if([_animators containsObject:animator])
        return true;
    [_animators addObject:animator];
    return _graphicNode->addAnimator(animator.native);
}
- (bool)removeAnimator:(QNodeAnimator*)animator {
    if([_animators containsObject:animator])
    {
        _graphicNode->removeAnimator(animator.native);
        [_animators removeObject:animator];
        return true;
    }
    return false;
}
- (void)clearAllAnimators {
    for (QNodeAnimator* animator in _animators) {
        _graphicNode->removeAnimator(animator.native);
    }
    [_animators removeAllObjects];
}

- (NSString*)name{
//    return [NSString stringWithUTF8String:_graphicNode->getName().c_str()];
    return _nodeName;
}

- (NSRange)renderRange {
    auto range = _graphicNode->getRange();
    return NSMakeRange(range._start, range._end - range._start);
}

- (void)setRenderRange:(NSRange)renderRange {
    self.origin_renderRange = renderRange;
    _graphicNode->setRange(Range<int64_t>(renderRange.location, renderRange.location + renderRange.length));
}

- (bool)visible{
    return _graphicNode->isVisible();
}
- (void)setVisible:(bool)visible{
    self.origin_visible = visible;
    _graphicNode->setVisible(visible);
}
- (float)rotation{
    return _graphicNode->getRotation();
}
- (void)setRotation:(float)rotation{
    QVector vertor3 = self.origin_rotation3d;
    vertor3.v2 = rotation;
    self.origin_rotation3d = vertor3;
    _graphicNode->setRotation(rotation);
}
- (QVector)rotation3d {
    auto rotation3d = _graphicNode->getRotation3D();
    return QVectorV3(rotation3d.x, rotation3d.y, rotation3d.z);
}
- (void)setRotation3d:(QVector)rotation3d {
    self.origin_rotation3d = rotation3d;
    _graphicNode->setRotation3D(GraphicCore::Vec3(rotation3d.v0, rotation3d.v1, rotation3d.v2));
}
- (float)scaleX{
    return _graphicNode->getScaleX();
}
- (void)setScaleX:(float)scaleX{
    self.origin_scaleX = scaleX;
    _graphicNode->setScaleX(scaleX);
}
- (float)scaleY{
    return _graphicNode->getScaleY();
}
- (void)setScaleY:(float)scaleY{
    self.origin_scaleY = scaleY;
    _graphicNode->setScaleY(scaleY);
}
- (float)scaleZ{
    return _graphicNode->getScaleZ();
}
- (void)setScaleZ:(float)scaleZ{
    self.origin_scaleZ = scaleZ;
    _graphicNode->setScaleZ(scaleZ);
}

- (CGSize)contentSize{
    GraphicCore::Size sz = _graphicNode->getContentSize();
    return CGSizeMake(sz.width,sz.height);
}
- (void)setContentSize:(CGSize)contentSize{
    self.origin_contentSize = contentSize;
    GraphicCore::Size sz(contentSize.width,contentSize.height);
    _graphicNode->setContentSize(sz);
}

- (CGPoint)position{
    GraphicCore::Vec2 pos = _graphicNode->getPosition();
    return CGPointMake(pos.x, pos.y);
}
- (void)setPosition:(CGPoint)position{
    self.origin_position = position;
    GraphicCore::Vec2 pos(position.x,position.y);
    _graphicNode->setPosition(pos);
}
- (float)positionZ{
    return _graphicNode->getPositionZ();
}
- (void)setPositionZ:(float)positionZ{
    self.origin_positionZ = positionZ;
    _graphicNode->setPositionZ(positionZ);
}

- (CGPoint)anchorPoint{
    GraphicCore::Vec2 anchor = _graphicNode->getAnchorPoint();
    return CGPointMake(anchor.x, anchor.y);
}
- (void)setAnchorPoint:(CGPoint)anchorPoint{
    self.origin_anchorPoint = anchorPoint;
    GraphicCore::Vec2 anchor(anchorPoint.x,anchorPoint.y);
    _graphicNode->setAnchorPoint(anchor);
}

- (QColor4)color4{
    GraphicCore::Color4F color = _graphicNode->getColor();
    return QColorMaker(color.r, color.g, color.b, color.a);
}
- (void)setColor4:(QColor4)color4{
    self.origin_color4 = color4;
    GraphicCore::Color4F color(color4.r,color4.g,color4.b,color4.a);
    _graphicNode->setColor(color);
}

- (float)alpha{
    GraphicCore::Color4F color = _graphicNode->getColor();
    return color.a;
}
- (void)setAlpha:(float)alpha{
    self.origin_alpha = alpha;
    GraphicCore::Color4F color = _graphicNode->getColor();
    color.a = alpha;
    _graphicNode->setColor(color);
}

@end
