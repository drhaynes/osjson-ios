//
//  OSJSON.h
//  OSJSON
//
//  Created by Dave Hardiman on 10/03/2016.
//  Copyright © 2016 Ordnance Survey. All rights reserved.
//

#import <Foundation/Foundation.h>

//! Project version number for OSJSON.
FOUNDATION_EXPORT double OSJSONVersionNumber;

//! Project version string for OSJSON.
FOUNDATION_EXPORT const unsigned char OSJSONVersionString[];

NS_ASSUME_NONNULL_BEGIN

/**
 Objective-C interface for parsing JSON in Swift.
 Intention here is to minimise the amount of `guard`s and
 casting required to handle JSON in Swift without the need
 for a 3rd Party framework. Not intended to be used as part
 of the public API for framework.
 */
@interface OSJSON : NSObject

/**
 *  Initialiser
 *
 */
- (nullable instancetype)initWithData:(NSData *)data;

/**
 *  Initialiser
 *
 *  @param data           The data to parse
 *  @param initialKeyPath The key path to use for the root object
 */
- (instancetype)initWithData:(NSData *)data initialKeyPath:(NSString *)initialKeyPath;

/**
 *  Get a string from the root dictionary
 *
 *  @param key The key for the string
 */
- (NSString *_Nullable)stringValueForKey:(NSString *)key;

/**
 *  Get an `NSData` value from the root dictionary.
 *  Assumed the value in the dictionary is a base64 encoded string

 */
- (NSData *_Nullable)dataValueForKey:(NSString *)key;

/**
 *  Get a double value from the root dictionary
 *
 *  @param key The key for the value
 */
- (double)doubleValueForKey:(NSString *)key;

/**
 *  Get a float value from the root dictionary
 *
 *  @param key The key for the value
 */
- (float)floatValueForKey:(NSString *)key;

/**
 *  Get an integer value from the root dictionary
 *
 *  @param key The key for the integer value
 */
- (long)intValueForKey:(NSString *)key;

/**
 *  Returns a boolean value from the root dictionary
 *
 *  @param key The key for the integer value
 */
- (BOOL)boolValueForKey:(NSString *)key;

/**
 *  Get an array from the root dictionary. No type information, so casting required
 *
 *  @param key The key for the value
 */
- (NSArray *_Nullable)arrayValueForKey:(NSString *)key;

/**
 *  Get an array of json objects
 *
 *  @param key The key for the value
 */
- (NSArray<OSJSON *> *_Nullable)jsonArrayForKey:(NSString *)key;

/**
 *  Get an array of string objects
 *
 *  @param key The key for the value
 */
- (NSArray<NSString *> *_Nullable)stringArrayForKey:(NSString *)key;

/**
 *  Get an array of number objects
 *
 *  @param key The key for the value
 */
- (NSArray<NSNumber *> *_Nullable)numberArrayForKey:(NSString *)key;

/**
 *  Get a child dictionary as an `OSJSON` object from the root dictionary
 *
 *  @param key The key for the value
 */
- (OSJSON *_Nullable)jsonForKey:(NSString *)key;

/**
 *  Return the root object as an NSArray
 *
 *  @return The NSArray at the root of the object
 */
- (NSArray<OSJSON *> *_Nullable)array;

@end

NS_ASSUME_NONNULL_END
