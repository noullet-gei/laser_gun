#include "../audio.h"
#ifdef USE_roca
/* pour utiliser ce son, declarer :
#define USE_roca
extern const unsigned int roca[];
*/
const unsigned int roca[] = {
8464,   // le nombre d'echantillons
0x43180080, 0x310c6208, 0xce538c20, 0x5224e739, 
0x8465394e, 0x02321061, 0x2a529280, 0x5ab48c23, 
0xd7aded7b, 0xadef7b5e, 0x52941cb0, 0xa529294a, 
0x9d085254, 0x59c62f49, 0xd6f5bd6b, 0x739ceb5a, 
0x7bdef7ce, 0xad4940ef, 0x6a52d4a5, 0xa212a5ad, 
0x6d8c6738, 0x8bdef6b5, 0x5ab4956f, 0x38c6717c, 
0xd6b3ace7, 0x738d6b5a, 0xb524f7c6, 0xa96b5ad6, 
0xe952d6b5, 0xc6739cd8, 0x318ce319, 0x5a5677c6, 
0xceb7b56b, 0x59d63179, 0xceb5bd6f, 0x926b675a, 
0xc5ad8b5a, 0xa96b62d8, 0x39ce6e54, 0xd6f5ace7, 
0xeb7ceb5b, 0x6b5af690, 0x6b5ace71, 0xf6d6b5bd, 
0x5ad6a528, 0xd6b6318b, 0x8cde2752, 0xeb39ce33, 
0x14c675ad, 0xadef58d2, 0xf59c50b0, 0xad6b7bd6, 
0xa927aeb3, 0x8c5b16b5, 0x4a54c62d, 0xb3ad66e6, 
0xad6b59de, 0x9cc4be35, 0x17aceb53, 0xdeb7bd67, 
0xebad6b5a, 0xb62d6a51, 0xad8c5b16, 0x59b90eb5, 
0xd6b7ad67, 0x882a6b5b, 0x6a1ce839, 0xeb79c567, 
0x59deb7ad, 0x5a899deb, 0x18b5b16b, 0x75318c5b, 
0xeb5bd6b0, 0x3ad6f5ac, 0x4a529b5f, 0xe96b5b15, 
0xbe6f5acd, 0xeb7ad673, 0x8b62937c, 0x62d8b5b1, 
0xb574ad8c, 0xad6b5bde, 0x9ed9ceb7, 0x07319094, 
0xde717291, 0x759def7b, 0x8cef7bde, 0xad6c62d6, 
0x6c6318c5, 0xdef799a9, 0xb5ad6b5a, 0xa4a0d8ce, 
0xded421d0, 0x5acdad6b, 0xd6f5ad6f, 0x71ad6b59, 
0xb62d8b5a, 0xad8b62d8, 0x7bdeae95, 0xd675ad6b, 
0x5493e359, 0x4a4ce74a, 0xeb39c62b, 0x3acef7ad, 
0x46b5ad6b, 0x16b62d8a, 0xa6318b5b, 0xef7bc854, 
0x59d6b5ad, 0x52502be7, 0x2f73a12a, 0xad6b18c6, 
0xe35ae6f5, 0x56cef59c, 0x6316c5b1, 0x96c5b16b, 
0xbdef79a2, 0x6739d6b7, 0x4a524f6d, 0xc5ee4429, 
0xf7ace358, 0x9cef7bde, 0xa73ace2f, 0x6c6318c5, 
0x52d8b531, 0xf7ce6f08, 0x9d6739d6, 0x2d6a492f, 
0x18bd8e95, 0xdeb7ace3, 0xf3bdef9b, 0xb4c338c5, 
0xb16d6318, 0xe95ad6b5, 0xdef9cde4, 0xed8c635a, 
0x95a96940, 0x6738b212, 0x7bdef5ad, 0xc675cdef, 
0xd6996316, 0xb6318d62, 0xd56b5ad4, 0x7be6f9bc, 
0x25ef8c67, 0x52b5ad49, 0xace71842, 0xef7cdef5, 
0xf8def7ad, 0x62d44b52, 0xd8c6318d, 0xbc1d4b52, 
0x679be737, 0x6a486f9c, 0x3a56b529, 0xf7ace714, 
0xbdeb9bde, 0x9b1adef7, 0x8d62a768, 0x5ad6c635, 
0x39b2296a, 0x7c677cdf, 0xad6a2df1, 0xd43254b5, 
0xe6f7acde, 0xb7adeb7b, 0x549f5bde, 0x35ab2670, 
0x6a52d6d6, 0xe73775ad, 0x6b7ceb9c, 0xb62d6929, 
0xdeb609d6, 0x7bdef7ac, 0xdeb5acef, 0x509beb5b, 
0xd6b15ad6, 0xa94a6318, 0x7de690b5, 0x2d318d73, 
0x56c62d69, 0xad62f642, 0x673cdf37, 0x3ad6b38a, 
0xd5f1adeb, 0x5ad59f5b, 0xa52d6c6b, 0x739cd014, 
0x694df3ce, 0x52d6c62d, 0xf9ad6726, 0x726b5be6, 
0x6b15a192, 0x5ad739bd, 0x73575d6f, 0x1095adcd, 
0xde777442, 0xad694e77, 0xc96318b5, 0xdeb7be6a, 
0x949aef7b, 0xbd5d0952, 0x639cef39, 0xce5d65ad, 
0xc612c6b9, 0x3bce6b18, 0xc5ad69d7, 0x5d6b62d4, 
0x59df39bd, 0x5a8f9be3, 0x39ad596a, 0xadefbce7, 
0x358b4d73, 0x394b18e7, 0xe739bd67, 0xd8c5aadc, 
0x84a96b5a, 0x6b7be735, 0x6a51b19c, 0xe737852d, 
0x37ce739c, 0xd6296942, 0x6eac6b5a, 0x7adeb7bd, 
0x5b14b46b, 0x6e54a94b, 0x5c6b7cde, 0xa9074a4e, 
0x7bde4354, 0xdef5be73, 0x50a4a959, 0x96358d4e, 
0x2129c6f4, 0x480ef781, 0x95ae062d, 0xf7ac2522, 
0x342516ce, 0x2129286a, 0x39def9bd, 0x54f9cdeb, 
0x578c292a, 0xbda96d6b, 0xeac941f5, 0x4c5ac99d, 
0x4a2f8c21, 0xadadf357, 0x4be50a5a, 0x73793a52, 
0x59be37ce, 0x5a914d6f, 0x9aa16744, 0x9e732b6b, 
0x73785315, 0xe962d75d, 0x42947c6a, 0x969cf37a, 
0x9c67014a, 0x6f7bde2a, 0x7acdf37d, 0x9d128cef, 
0x5ad5977a, 0x8d672b6b, 0x6f9cd251, 0xc963189d, 
0xc9d2a3e2, 0xd49d6f7b, 0x7c630852, 0xf37bcdad, 
0xc84a2bcd, 0xc0f1bd60, 0xd69ce719, 0x85b1ad6a, 
0xd318d737, 0x8b55f5ab, 0xce7384b1, 0x75bce319, 
0x94ad6b46, 0xa0e6ceb7, 0x3bd737a3, 0xd6af4524, 
0xcc649f7b, 0x94a959cc, 0x2d8d6290, 0x08d6b7bc, 
0x467382a1, 0xf794ad6b, 0x452526de, 0x2931ae72, 
0x3ad6b315, 0xd6f3729f, 0xae341f39, 0x949b3bde, 
0x2d45d662, 0x8c5d8aa6, 0xce7994ad, 0x317428f9, 
0x652968c6, 0x20f1e6f0, 0xe6c6a2a5, 0xd6f42528, 
0xf503a2d9, 0xa52afae6, 0xef7bde92, 0x599a14b4, 
0x6318b56f, 0x1698eb53, 0xae6f585b, 0x690b52d3, 
0x0a5a2b9d, 0x526fad64, 0x4dacdeea, 0xbdeae23a, 
0xe4b6be73, 0x273d652c, 0x51ef8d6b, 0xabac992a, 
0x8d154b5a, 0xe8ab5ad6, 0xe94e359d, 0x5a759b50, 
0x2bbda549, 0x8d556939, 0x5c8aa633, 0x38be779c, 
0x0d35ac63, 0x339ca535, 0x6c21491e, 0xa54a462d, 
0x6b62ae14, 0xceb9bca9, 0xb3742968, 0x752d69ce, 
0x2916d6f4, 0x18d67405, 0xdef05429, 0xaf7b633a, 
0x745ec3ce, 0x2915be70, 0x57ce3445, 0xcdcea5a9, 
0xf4b5b18a, 0xb51b5be6, 0xa71ac80e, 0x7bd1d4b5, 
0xc256a2df, 0xd29ceb3a, 0x8cef79c5, 0x6b59420d, 
0xe842639d, 0xb0c8511c, 0x92a4a2e5, 0x83ad6b5a, 
0x1e99def5, 0x48b58874, 0xc66e53a1, 0xd0738ad8, 
0x819aa641, 0x673ad631, 0x18b10b3c, 0x38cd1c67, 
0x2c11dee9, 0x7320c84a, 0xa968b1af, 0x3ace1295, 
0xbe0882e3, 0x949528d4, 0x9c6737a1, 0x6b19c62d, 
0xe51d73ad, 0xce77adea, 0x50a5a926, 0x75ad8c5a, 
0xa6dbdef4, 0x25cc9094, 0xde82a5a9, 0x52a46b7b, 
0x938f182a, 0x6f324994, 0xa739b3ad, 0x31ad7acc, 
0x6d9ce2b6, 0x685507ad, 0x15094a4e, 0x8639e941, 
0x39876a48, 0xed481908, 0x2c62d5c5, 0x0ec13d65, 
0x19b6718a, 0x99d19c63, 0xe86a5d28, 0x84a92949, 
0x16d23ce4, 0x2719ad8b, 0x388e7819, 0x738b0ca7, 
0x8c62f8c6, 0x6338ce71, 0x843d285c, 0x5292838a, 
0x0383252a, 0x2bd8c4b0, 0x90c60085, 0xa74a0693, 
0xbe73ac54, 0x739c6318, 0x225719ce, 0x8a97c549, 
0x2b5ad4a4, 0x0d6f6b9d, 0xf39c62f6, 0x4425292d, 
0x1275ce31, 0xe5a5aa43, 0xbc8e7520, 0x6f6a1298, 
0x70ded8c6, 0x5719d671, 0xb4c50e73, 0x42d4a4a0, 
0x8f2b5ea8, 0x8c62f439, 0x502520ad, 0xb5adb17b, 
0x41c81b5a, 0xe6232508, 0x1aceb7b5, 0x9654b62c, 
0xf7898c73, 0x318c58d2, 0xce1adaa1, 0x6b5ac531, 
0x524588eb, 0xa52c295a, 0xb5ab3a8c, 0xeb221094, 
0x339c859c, 0x9436aca8, 0x329cc438, 0x94023146, 
0x48008893, 0x3a54458d, 0xcea0a90a, 0x07b5ca60, 
0x91aa8c1a, 0x52d6778c, 0x9ce599c7, 0xb2ead2f4, 
0x3a5915cd, 0xcab14d5d, 0x559566e6, 0xc5279c6d, 
0xe70bda7a, 0x144699a3, 0xa9328ca8, 0x6a92dad7, 
0x0222f346, 0x1ec4b9f1, 0xf52a2394, 0xad0a1a8a, 
0x6ab29f29, 0x6df58d9f, 0xaf8cdaca, 0xdd5af163, 
0xda6c75d8, 0x93a42b46, 0xa6a15a4e, 0x6faec23c, 
0x7c675bbc, 0xd336bd2d, 0x754c1f4a, 0xa5ed671e, 
0x2b6a2db1, 0x7a4d727d, 0x4f5ab3ed, 0xb4ae774d, 
0xa5ed76c2, 0x6d095659, 0x635f7185, 0xc1d0a3ab, 
0x6d9ca4e8, 0x65691b5e, 0x66ea40ac, 0x2bc6b2c2, 
0x96648ded, 0xf3966358, 0x952b8cba, 0x273a46c5, 
0x973274ce, 0xe2578269, 0x51bca558, 0xcd64ea46, 
0x750b2e34, 0x6cded0a6, 0x67129c27, 0xb29a68f9, 
0x63a76ac2, 0xdef85cb6, 0x28ae72cc, 0xcab515f1, 
0xd4ad2f8b, 0x8ded8ad6, 0x293ad556, 0xb84c57bd, 
0x5a76ad26, 0x15c55d9c, 0x9e5d6aeb, 0x6b055f18, 
0x1a52b8b4, 0xe257c5d5, 0x589eb129, 0xace57ad6, 
0xab765134, 0x3b3af5b5, 0xd9d45d1e, 0xf362d529, 
0xb326c6c2, 0xd32a46d9, 0x295eb4cb, 0x42f685e7, 
0x73baaf79, 0xac5d5cd2, 0x1369ae75, 0x7ab9649d, 
0x5216b3e5, 0xaea6652c, 0xa52f8a51, 0x273b6577, 
0x99c9d364, 0x16376cee, 0x33bde75a, 0xcbeaf6ee, 
0x358c4ed3, 0x8b59dad4, 0xd23754f1, 0xd9959f7b, 
0x7ca56b49, 0x6b1cceb4, 0x09caa7ad, 0xceb21a89, 
0x73ce739b, 0xcbeb39da, 0xa98d62da, 0x9a61f2b6, 
0xd177cd2f, 0x96bc197a, 0x5b68ea4a, 0xdf5cce79, 
0xaa2a1194, 0xdef59c26, 0x77cbef9c, 0xd628fbba, 
0xb50c6ad8, 0xbbca1594, 0xd1b1bdec, 0xd2c4a14a, 
0xbc635859, 0x5a5bd5b9, 0xea35d27b, 0xdeb7816a, 
0xd35e229c, 0xb66f2bbe, 0xad8b4314, 0x495598b4, 
0xceb7ac1f, 0x148ae35a, 0x5ca12942, 0x9737ccf1, 
0x7c4ab38a, 0xe5297c81, 0x53a2df6b, 0x9c1eb83e, 
0x9ec84e28, 0x44b20272, 0x41d092d1, 0xce842249, 
0x2aa10639, 0xe6f8c4cc, 0x05cdefaa, 0xb62f4bc7, 
0x6f80e316, 0x6b9717b6, 0x4cf6a147, 0xe741ca83, 
0x41d27324, 0x12741d28, 0x639ce73a, 0x62f6b922, 
0x17c6718c, 0xbdcb9b63, 0xac4bc656, 0x32d2a5a8, 
0x90330c21, 0x669d4a19, 0x120a4380, 0x8c731ce7, 
0x52188639, 0x58311c0a, 0xa3bde35a, 0xb86d6bde, 
0x0519d415, 0x5154928d, 0x4635a469, 0xc234ec20, 
0x240c1292, 0xa81340c4, 0x5294a119, 0x54b33126, 
0xe0b14702, 0x256f6006, 0x6238ca77, 0x2ac0d2a9, 
0x0202a10a, 0xb5216132, 0x85006950, 0xa9135686, 
0x5a84b20c, 0x54259548, 0x93802858, 0x1c420944, 
0xe0020e61, 0x294a2090, 0x84350026, 0x01950729, 
0x042619ca, 0x02110232, 0x40084311, 0x88011842, 
0x3080a220, 0x8845108a, 0x80280821, 0x294a3090, 
0x867194a3, 0x5008e438, 0x98031006, 0x41190a21, 
0x08c61080, 0x066004a2, 0x21942219, 0x90c20082, 
0x63188e01, 0x1946208c, 0x86028440, 0x23804228, 
0x88c2208c, 0x26588222, 0x180a2100, 0xc26188c0, 
0x50986719, 0x086019c6, 0x60290a63, 0x188e9004, 
0x822290a6, 0x72a06818, 0x8080090a, 0x60210a41, 
0x10c47110, 0xce04a0e4, 0x70904418, 0x0c604a92, 
0x824a4cb5, 0x1a9ab324, 0x9ec29943, 0xc594805b, 
0x1e138292, 0x632b2306, 0x4246a6b1, 0x809738a9, 
0xd2888752, 0xb1ed6460, 0x517216e6, 0x6accd84e, 
0xe11845c2, 0x08b9b080, 0x39f4ac23, 0xeb7460f7, 
0x74e936a1, 0x2748b232, 0xd8318d94, 0x56918458, 
0xd7b56077, 0xdeb73e76, 0xf5bbe2f8, 0x8deb17d6, 
0x558d912f, 0x74bda81a, 0xd6f19c5d, 0x338a2e57, 
0xbe7759ad, 0xebbcd371, 0x19d6f06b, 0xa5674dea, 
0xf5de6f17, 0xaef37755, 0x675bd62b, 0x59c52338, 
0xb5f5de77, 0xf5bc5655, 0x7f7f76b5, 0x7794df39, 
0x7acf3fd5, 0xbebbeff3, 0x3beff196, 0xdf7f78de, 
0xe3bcdcf1, 0xdde7fdfe, 0xf7f4dd7f, 0x6dfdf397, 
0xcfe758df, 0xf35df7fb, 0xb6df3bad, 0xeeb3ad26, 
0xfdfcebfe, 0xeff3bca6, 0x7fdffcbb, 0xfcffbfed, 
0xc7fddb41, 0x25be6b7d, 0x8efbfeff, 0x7ff4eeaf, 
0xfcdf3fbd, 0x67fd2efb, 0x3fda633c, 0xdbd69dee, 
0x6b7ee77d, 0x1ff775df, 0xaeb78def, 0xfdff77df, 
0xcefbdbf7, 0x7f9ff437, 0xbcffb9bf, 0xc499df7f, 
0xf12efbb1, 0xcdfbf894, 0xeb49e77d, 0xdcefbfed, 
0xc6f73677, 0x3beff3fe, 0x9e7fdfee, 0xebfeffb1, 
0x5ff779da, 0xd22f4ce7, 0x343a6f9d, 0x9f7f96df, 
0xfbb6dfb9, 0x99f7fdeb, 0xbf35bcf3, 0x2baeeed8, 
0xb7f35be6, 0x6fb4ffb1, 0xfdbd329b, 0xcf314efb, 
0xdddf7fdc, 0x8cfbfcee, 0xf59de671, 0xb6bead8c, 
0xe618cbf3, 0x3faefb5b, 0xcdf59fef, 0x779dbf3f, 
0x1dbfbd3e, 0xcfbdbe5f, 0x71bee3fc, 0xabebbbd7, 
0xeb15cdbb, 0x91a233ad, 0xb4e9bd5d, 0x6b1b5337, 
0x07c2b736, 0xded9d6f1, 0x161a33ce, 0xb679dd67, 
0xb0fc4af8, 0xccea59cc, 0xebbd877d, 0xdffb3bcd, 
0x96738eee, 0x379d7732, 0x9647189e, 0x5e57d6f5, 
0xd9c5ed9c, 0x95ef8dd6, 0xa57d6ef2, 0x6ae65bca, 
0x527685f1, 0x51b6719c, 0xc52b8cda, 0xdd9c9a97, 
0x6bdab6cd, 0x533a85a3, 0x57b50d5c, 0x656cebe1, 
0xa69590f1, 0x5a2a53a4, 0xd993aca5, 0xf655f14a, 
0xb428da42, 0xeb0bda15, 0xf8d253b5, 0x36976dac, 
0x3793e15a, 0x6caf57cb, 0x1b4a4ed7, 0xba563565, 
0xe20c9da8, 0xb283e2ac, 0x8d2f65ca, 0x6d67d213, 
0xe7d2f6ba, 0xe336629a, 0x55859f4c, 0x9969103e, 
0xab48c1f2, 0x29beacbd, 0xd2f884ec, 0x19add6d9, 
0x9ce72ce7, 0x9d6b6692, 0xbaa314b5, 0xe1d27d61, 
0xb1a56cea, 0xcdab5ac2, 0x737dd977, 0x6b4735cd, 
0x6a16e665, 0x76a3336e, 0x9e651dd2, 0xad4c36d9, 
0x3c5a2ec5, 0xe6edae97, 0xf5736af7, 0x9e778bd6, 
0x294d6776, 0x2b5b58b7, 0xef11cda9, 0xda84e538, 
0x95292a69, 0x6f5cd735, 0x29c20f9d, 0x4777ad51, 
0x7bc573da, 0xd6b54c73, 0x710bd19a, 0x6ce735be, 
0x5b14c623, 0x39bd28ea, 0x756f59de, 0x5f534a71, 
0x9ddebbbd, 0x6b59cd6b, 0xa8d6b5ab, 0xad6fb65e, 
0xb51b663b, 0x493318a5, 0xbf384d72, 0x96a52b79, 
0xce728ad5, 0xdb9c3f79, 0x8d6b547d, 0xd5d0a6b1, 
0x53cdeb5b, 0xcc318cd6, 0x6b7a3658, 0x383277bc, 
0x399345a5, 0xf7cd6b9b, 0x4eacfce6, 0x358cda96, 
0x87698ab6, 0xd2797667, 0x5675283a, 0x94ea4a56, 
0xa6da3ab5, 0xe1da5393, 0xdeb46e6e, 0x68ad6f71, 
0xc5f139c7, 0x310a631a, 0x58cd4f75, 0x52903de7, 
0x52ac2987, 0x946b47ce, 0xa2e851f5, 0x5bd63363, 
0xc6efbd6f, 0xf5cdaf3b, 0xd6b164c9, 0x1cc96256, 
0x18ee157e, 0x5a96a4a9, 0xb78c14e9, 0x841ef9a6, 
0xed4831d2, 0x5adf35ab, 0x5ef27de7, 0xfb4c6b87, 
0xb62d8d4a, 0xda9a4ada, 0xe736b7bd, 0x4acac5a8, 
0x519deb39, 0x62ad68d6, 0xe77a3a12, 0x773eb9bd, 
0xb6377567, 0x6b9ceb9b, 0xc3b5ad5a, 0x6f5abe1a, 
0x495e79ad, 0xb252b52d, 0x55be6738, 0xa52d50aa, 
0xeb5bc4e6, 0xb9ceb7bd, 0x9275bb26, 0x319cef7c, 
0xc3b5ad62, 0x677bba96, 0x6a3a35cd, 0xb6d4b5ad, 
0x8f8deee4, 0x34ad49aa, 0xf35ad655, 0xc4c6f7bc, 
0xb6b3809e, 0x32ad7399, 0x96b5ac52, 0x6f7bdb59, 
0x4ca6f26e, 0xd252962d, 0x51aded5b, 0x662aa952, 
0x6efaddb4, 0xa6c6b37e, 0xce35a45a, 0x37abef5b, 
0xe5ada8c9, 0xef4b569a, 0x575679b0, 0xcb16b5ab, 
0xb1bdde87, 0xa5a929ae, 0xeb5b92f4, 0x27df15ad, 
0x42359b19, 0x15ad6b7b, 0xbbe505d7, 0x8dad4356, 
0x9a56f534, 0x5ab48553, 0x957c9589, 0x821311e6, 
0x0f186292, 0x29def59b, 0xd66b9b67, 0xf57beb07, 
0xa3673a1e, 0xa528aab3, 0x084b58c5, 0xb7232d23, 
0xf2b66f0b, 0xcd273952, 0x8962d155, 0x89517094, 
0xd6f08d63, 0xf19b6956, 0xbce378cd, 0x9efac5ab, 
0x4c49d0ab, 0xd652e66d, 0x37cc3357, 0xa5235a5b, 
0xeac8c652, 0x29b1d1a1, 0xb2109ba1, 0xaf9ae779, 
0xac6b4646, 0x9f1bc0b5, 0x2add8fbc, 0x560ecc65, 
0xf6b6ad2b, 0xbda72151, 0xa13bc2d7, 0x474eb295, 
0xbaa998df, 0x559c2566, 0x04179ac9, 0xed38b674, 
0x47de4f8d, 0x56f562e3, 0x4c9ca109, 0xb7281a2b, 
0xace84ef6, 0x5ccb179e, 0x4ef0851d, 0xb2a3ef4b, 
0xab2e7952, 0xa75caacb, 0xeabecdab, 0xb6729df2, 
0xf364575b, 0x9d508c36, 0x333ac2d8, 0x295f38c7, 
0xe359bea1, 0x36a6215c, 0x8b736c57, 0x317baa96, 
0xc7cb37c4, 0xbed0bdf2, 0xf79ce703, 0x246b3a46, 
0xac8b3df5, 0xbb5ad39c, 0xde18d5e6, 0xb9aca94a, 
0x85eb9062, 0x25278e54, 0x16ba954e, 0xda948565, 
0x365c8f59, 0xbd6eea4f, 0x9f7c3ab3, 0x6ab1af4b, 
0x52538c29, 0x94e5ef33, 0xc32147c6, 0x6b986af9, 
0x78d694b5, 0x9ac79da1, 0x98a56536, 0x9da4fae6, 
0xf3495f38, 0x7cbb37b4, 0xe2598e2b, 0x7973ad8a, 
0xd6eb4b66, 0xb137c9ca, 0x5c3b05dd, 0xcf52d562, 
0xb78bed6c, 0x85a76a62, 0xe51bc633, 0x57e6d77d, 
0x56f864e3, 0x17cc2b3c, 0xb4712a4b, 0xb998d694, 
0x5952f3d6, 0xeeda8e71, 0x7885a96c, 0x75d7b966, 
0xada7d297, 0x67c655be, 0xc738c677, 0x537de76a, 
0x85271dd2, 0xe92bc255, 0x8856d2cd, 0x4b37c635, 
0x1ace7308, 0x85294ae7, 0x6b786279, 0x6bb9d4a1, 
0xce613de1, 0xf525eb79, 0x8de35a3e, 0x6b39e232, 
0x9a6a6aa5, 0xcb0c9457, 0xf375b579, 0x2ded2955, 
0x2ee4c1d5, 0x564db735, 0xb514b4eb, 0xcfcdad77, 
0xa46f5aba, 0xe285d732, 0xbdd1d1bd, 0x5db09528, 
0x1aad712b, 0xc6af1bd2, 0x9ccb5ef4, 0x5acad7cd, 
0x3ec4a249, 0x9484eb2a, 0xc2b119ca, 0x702449b5, 
0x3ae6949d, 0xc67593df, 0xcaa5677a, 0x8ddd2b4d, 
0x575a3b17, 0x2bc6d6d6, 0x4333c289, 0x948b2afb, 
0x8c6d49c6, 0xaf5a42ce, 0x472ef5a5, 0xda0dae61, 
0xf6a56b79, 0x9ce6bad6, 0xe7464317, 0x395dd0a4, 
0xc2da8ba5, 0xb47864e8, 0x64de894e, 0xa737a9d2, 
0xb74a7279, 0xd54fa3a0, 0xd16d5a77, 0x136b3ace, 
0x275ace77, 0xe652978d, 0xca56bde8, 0x6455274b, 
0x43cb0b64, 0xad5bd2f1, 0x0bd9959c, 0x6676b465, 
0x917c6769, 0x9aa55bda, 0x6f55c6b5, 0x5bc6315d, 
0x4a1343a7, 0x969e5946, 0xa596e8b2, 0xe16c5ed0, 
0x5b42d37d, 0xbef295ab, 0x957de56b, 0x92a71932, 
0x68a8c6a3, 0x3ade6e7c, 0xa875ab5b, 0x5693e75b, 
0xaba911d2, 0xeca9564e, 0x79921485, 0x42b3a931, 
0x96c2728a, 0x88ae06d6, 0x5f584a75, 0x07d6d4ac, 
0xc9f59ae9, 0xb39ca77a, 0x6ceb06b6, 0xacf9cb0a, 
0x4aa155ac, 0x5692b469, 0xf3b4a969, 0x9add172a, 
0xc7094654, 0xf7be2c93, 0xbdaba084, 0xf47ce846, 
0xba9b19b6, 0x5f17cdf3, 0x562a956c, 0x4d508d45, 
0x5553e4eb, 0x9b2d274a, 0xe90a4273, 0xe8c2128a, 
0x5670319c, 0x75956347, 0xada679ca, 0x6099d62d, 
0x4a36b56c, 0x3a688bdf, 0x97949d3a, 0xb3a0caae, 
0x6169ca12, 0x675a2b54, 0xc242931f, 0x6d8c2959, 
0x94eb09c6, 0x1cbbb1c9, 0xe9d6b39d, 0x56759c60, 
0x9185e778, 0x9da17aba, 0x0f0b3e96, 0xf65cb4a6, 
0xbad59d24, 0x70939ef5, 0x726aca46, 0xa51ba20f, 
0x27c6719b, 0xbdf39d67, 0x6f9c62e8, 0x155b3a42, 
0xa54acd20, 0x01524f59, 0x31ae95d7, 0x6c51acf7, 
0x82e0e412, 0x22e82e4e, 0x3932756c, 0xde9198e3, 
0xf47b5f20, 0xbaaadac1, 0x68eb4647, 0xf93ad29c, 
0x39b135a6, 0x8eac2909, 0x855d1649, 0x9ac6bc65, 
0xd9c56c9c, 0xae7382e6, 0x8a6aeb58, 0x8c253acd, 
0x630739b3, 0x47455494, 0x520b68a4, 0x8e6560d5, 
0x7c2509c2, 0x60c84e6e, 0x19ba0d7a, 0xd66d6c1b, 
0xef3beb16, 0x82a2da15, 0xe2669def, 0x443a529b, 
0x416e24a0, 0x8eac54ca, 0x8524b649, 0x9528ccab, 
0xf84e2c7c, 0xcd6d73e6, 0x496d5f38, 0x649b59b1, 
0x6921c5f0, 0x3251d41c, 0xba248523, 0xd07c14e8, 
0x8514e449, 0xd828b567, 0x19a94c7c, 0xaeb2349f, 
0xe3acdee6, 0x9ce4b841, 0xa731cc52, 0x4855f254, 
0xaa159be1, 0xe0939ef7, 0x6a5d28b5, 0x9f1429e2, 
0xc51dad72, 0xb5ee5c58, 0x0192d6b6, 0x7b58a316, 
0x271701aa, 0xe7c09051, 0x4cf034e0, 0x137c22e1, 
0x54dcd5ba, 0x96e4356d, 0x04bc6c7b, 0x35ab90c5, 
0x6c7956d4, 0x729e78b5, 0xdce51423, 0xb6118e7b, 
0xa8ee739a, 0xe54b18a8, 0x534eb540, 0x1900c54f, 
0xe62daf4b, 0xc4a8505a, 0x2b209631, 0x6904f72d, 
0xdc672d49, 0xb8b9cc71, 0x3dec19a6, 0x104c62c9, 
0x739c58b2, 0x58882def, 0x57c18c5b, 0x45b16398, 
0xd06be267, 0x3322b8b1, 0x5cc71dae, 0xf70c504b, 
0x0d7013a2, 0xcf5c5ce8, 0x73971621, 0xd0f3b5c2, 
0x8281a75a, 0x2d68424a, 0xc75ac622, 0x68861391, 
0x145395c0, 0x2291a552, 0x95a2794e, 0x45629615, 
0x6b560381, 0x52552c86, 0xa5b12121, 0x2d681a1a, 
0x0b295492, 0x499a5099, 0x54259d2a, 0xb410c931, 
0xa4a60896, 0xa038d445, 0x62985514, 0x54659ce1, 
0x9608ca5b, 0xac6d4396, 0xca1b54c5, 0x428a9420, 
0x80849ce8, 0x1221094a, 0x8d644240, 0x09598442, 
0x31469201, 0xc4b19520, 0x81092548, 0x848420c2, 
0xc1180232, 0x38ca3108, 0x00008804 };
#endif
