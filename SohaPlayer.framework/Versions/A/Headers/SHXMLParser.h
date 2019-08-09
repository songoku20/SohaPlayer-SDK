//
//  SHXMLParser.h
//  ParsingXML
//
//  Created by Build Server on 5/20/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SHXMLParser : NSObject

@property (nonatomic) NSError *parseError;

+ (NSDictionary *)dictionaryWithData:(NSData *)data error:(NSError *__autoreleasing *)error;
- (void)reset;
@end

NS_ASSUME_NONNULL_END
