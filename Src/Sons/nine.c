#include "../audio.h"
#ifdef USE_nine
/* pour utiliser ce son, declarer :
#define USE_nine
extern const unsigned int nine[];
*/
const unsigned int nine[] = {
5272,   // le nombre d'echantillons
0x02000260, 0x00420080, 0x04110c60, 0x41080200, 
0x19044104, 0x69200462, 0x7bded6ad, 0x6318c631, 
0x0505ad8c, 0x529494a1, 0x5295294b, 0x229ce842, 
0xe739be29, 0x5ad6b5ac, 0xd6b5ad6b, 0xab7ce739, 
0xa5252838, 0xad8b5a96, 0xea4ad4b5, 0xd6716aa0, 
0xf7bdef5a, 0xbdef7cde, 0x86f9d6b5, 0x6b529293, 
0x5ad8b5ad, 0xd0a4ad6b, 0x6bc6c631, 0x6739ce31, 
0x59d6739c, 0xd675aceb, 0x319d6759, 0x70c6b7c6, 
0xad4a5250, 0x8b5ad6b5, 0xa95295a9, 0xb5ace716, 
0xbd6f5bd6, 0xeb7adeb7, 0xf7d675ad, 0x5a94938e, 
0xd8c62d6b, 0x74a96b5a, 0x5af22150, 0x39d6339c, 
0xd6b59d67, 0xb5ad6b59, 0xadeb5ad6, 0x1b17c677, 
0xab5ad695, 0x5ad8b631, 0xac84250b, 0xad6714c9, 
0xe75aceb5, 0x39ceb3ac, 0xd6f5ad6b, 0xf3bd6f7b, 
0xb52d47c4, 0x2dac6318, 0x265294c6, 0xcdef7a9d, 
0x75aceb59, 0xace739d6, 0x6b39ce71, 0x7bd6f5bd, 
0xbdb1adeb, 0x18b5a969, 0xb5b18c63, 0x44e94296, 
0x58be717b, 0xce35ace7, 0x319ce339, 0xbd6b3ace, 
0xef5bdef5, 0x4a3d2fad, 0x62d8b5ad, 0x96b6318c, 
0x7bd0e84a, 0x6b39ce31, 0x19ce339d, 0xd6339ce7, 
0xf5adeb59, 0xbd6f5bde, 0x2d484cb3, 0x6d5b16c5, 
0x5a96b631, 0x6d925917, 0x9d6757ce, 0x5718cdb3, 
0x3ac6b19c, 0xdef7adef, 0x35bd6f7b, 0xb5ad264a, 
0x2dac5ad8, 0x2a52d6b6, 0xcdb2394e, 0x738d6318, 
0x9b67181e, 0xeb39ce71, 0x5be6f5bd, 0x4ef5bcf3, 
0x16b52916, 0xc6318c5b, 0xe14a5a98, 0x19be6983, 
0xc6358ce3, 0x719c5f36, 0xadeb19ce, 0xef7bdef5, 
0x27d6b7ad, 0x6298a49d, 0xd8c6318b, 0x6ca56b5a, 
0x6b38b9ea, 0xb8beb381, 0xce719ce2, 0xb7bd6b59, 
0xadef5be6, 0x1d37d6f7, 0x8b62d6a5, 0x5b14d62d, 
0x0d832d0c, 0x98eaf90e, 0x4ef8ce71, 0x5ad5b38d, 
0xdef5bd63, 0xf7ad733c, 0x7524face, 0x2d8b5b16, 
0x4a6318c6, 0x4651a4ad, 0x73996a99, 0x4d2337d1, 
0xef19ce73, 0x7cceb7bc, 0xd777bdef, 0x91aa3737, 
0xd64dad53, 0x293a629a, 0x0acef9ac, 0x4254b4ed, 
0x37bca759, 0x9e7377bf, 0x673d4eb7, 0xdadf313e, 
0x6b1686b8, 0xd8c46d6d, 0xb52f3bd1, 0x212b55f7, 
0x1bd194bc, 0x9ef7bce9, 0x75bcf359, 0xadf2fce6, 
0x35daccba, 0x6c6b58b6, 0xeeecd56f, 0xd5bdad9b, 
0xa5df4b62, 0x615bde82, 0x3c52b5ae, 0xe777aceb, 
0x17def369, 0x87bf5d4b, 0x796e3216, 0x3dcb168e, 
0x5de15635, 0x0e6b734c, 0xbe2dbbea, 0xefba5211, 
0x06dfb9b5, 0xdb59bef5, 0x3ad7bf9c, 0xdf7dcc6f, 
0x3f7be31c, 0x0a607bb5, 0xe656d37b, 0x0ddd3579, 
0xbd73ba5d, 0x695aeeb9, 0xbb62f7be, 0xeecef7af, 
0x95cee5ac, 0x96b77c63, 0xf56ddf37, 0x7cda5aac, 
0x5637c3b7, 0x11ce7747, 0x5e6b4cf7, 0xf3bb6af8, 
0xc6ed94f7, 0x6b8bcf31, 0x36572f7d, 0x9e718de7, 
0x333dcb59, 0x4a49b9c6, 0xef498ef7, 0x7bcded59, 
0xf7f79a5b, 0xb9dce75c, 0xb86b91bf, 0xee766763, 
0xdb4de98c, 0x35af7cca, 0xf72bdeb5, 0x9de6b88e, 
0x6f381ce8, 0x9ef4f339, 0xd8b97ee2, 0xf78d75af, 
0xbce654d4, 0x630dce35, 0xcac5778a, 0xce6975e6, 
0xeb7d967b, 0x6c8f369d, 0xdb5eed5b, 0x7bd6b77c, 
0xdd734e62, 0x351ddeda, 0x8d62f5c5, 0xe216c4fb, 
0x39de315d, 0x7ee3b9bf, 0xe324cf12, 0x97bb9edc, 
0x3b39d6ab, 0x56bd558c, 0x4b2f7b5e, 0x71574b2f, 
0x59e596ad, 0x56fbcd5f, 0x17be6f7c, 0x7e1d8aef, 
0x6bdd6bdf, 0xcde738c7, 0x6b55deb1, 0xd8a5e3bb, 
0x9edd8ad6, 0x579c5a90, 0x64def9cd, 0xd6b9b577, 
0xdddeadbc, 0xe67bc17b, 0x35ddaf12, 0x0d59b9b5, 
0x3b199cf3, 0x3785271c, 0xbe6f0356, 0xa95ce73a, 
0x09d6fbcc, 0x7bf59e63, 0x9aee774c, 0xc5b934d7, 
0x75685b37, 0x7a5a30dd, 0xce549cd3, 0x3b9c62d7, 
0xade17dd7, 0x2f7ce6b8, 0xaf7dfb75, 0x5b5dafe9, 
0x56d76bdb, 0xbe31d8e7, 0x778d69f9, 0x5c4b0aad, 
0xef348ced, 0x75cbab7b, 0xa5df9cdd, 0xb5efe751, 
0x6d637de6, 0xea9cce73, 0x35c737a6, 0xbddd6ee7, 
0x6ae95df3, 0x5de6ef5d, 0xddb7b4a3, 0x7acbf73a, 
0x97bd3d55, 0x71aef79b, 0x685b93bc, 0x1692a56f, 
0x2db63278, 0x952f49bf, 0xf39a2ef5, 0x5abecbad, 
0xe233de2b, 0x9ed4798b, 0xe777be6b, 0x39dce6f6, 
0xed6efbbd, 0xdb589976, 0x52c5637d, 0xde495bde, 
0xf39915b3, 0x7ce6b0a3, 0x467285eb, 0x3bdeb5ee, 
0xad73ad73, 0x2f9bc31a, 0x3ade94b6, 0xbeb3cd35, 
0x4dad6cec, 0xa3dc9ce5, 0x6f66aef7, 0x865d75be, 
0xd39ed3eb, 0x30e767dd, 0xb4a5caef, 0xf36b6a79, 
0x9ddadabd, 0x36f8c6c7, 0x37cee578, 0xbef36a59, 
0xe37cbe4e, 0xccdf159d, 0x673db63d, 0x1bce9d4e, 
0xc5f38a63, 0x319be5d4, 0x4b4f3995, 0xaab79c9d, 
0xd19cf37b, 0x726b5bdd, 0xef79de77, 0x8f6b4fc5, 
0xc3dbdef5, 0xd6e6f3bd, 0xca357ae6, 0xf50c6577, 
0x9b4b170d, 0xef06a5e7, 0x37ad6514, 0xed6b29af, 
0x778be319, 0xdc9bdac6, 0xe6d0e5f0, 0x3b96359c, 
0x9d716b5a, 0x1f9c3b70, 0x93d714c5, 0xe6f7a55e, 
0xb9bde528, 0xaceb790d, 0xb777c76c, 0x98eadeb5, 
0xdf38c72b, 0x17ce29ac, 0xb51bbb63, 0x2cfbde98, 
0x45073546, 0xce73b327, 0xf3bd6b79, 0x8dd4f9c6, 
0xb1455f39, 0x9de71ce5, 0x6f7b95b9, 0x58be698c, 
0x36b39d82, 0xe98be6b0, 0x5446b884, 0xe7128d1f, 
0x6fbe32db, 0xbde74c57, 0xaf7a66f7, 0x5ce6dcf4, 
0x6f3db63b, 0x18bf49ad, 0xb62fbc5d, 0xad87d716, 
0x9a5a526e, 0xde76356f, 0xb9be5d9b, 0xade192de, 
0xefa76f37, 0xbaeb9ec5, 0x477aa733, 0x1bceb18d, 
0xb773a4db, 0x31b6e5b6, 0x835b33de, 0xeef4b6f7, 
0xbbdc1998, 0xc5f75051, 0x307dcef4, 0x9b7b959a, 
0xcf1ace67, 0x4eb52d19, 0x9ddb7a66, 0x2f1b4a56, 
0x684eb685, 0x5a529eed, 0xf8a5639c, 0xcda57bde, 
0xf3ac56b5, 0xdadb2d94, 0x677bc63d, 0xd8bc770e, 
0xbdb91cb2, 0x696c5f75, 0x7c5a94ae, 0xdf3685ab, 
0xb79b6d6b, 0xbcaf9b3c, 0xab79d6d1, 0x1832b9c4, 
0x5b9abd29, 0xf6d56efb, 0xb52989d6, 0xf15a4b77, 
0xe9b690cd, 0x5333b3dc, 0x14cbe75c, 0x9366b0df, 
0xed5755fb, 0x5d42cf6e, 0x5f78c5a7, 0xb6d6a98b, 
0x1e299b45, 0x6ae842d6, 0x69c6b8c6, 0xdad5aba0, 
0x51955cfa, 0xb2ab19c6, 0x9f7bc673, 0x8aded49d, 
0x32b445ef, 0x1ba5337d, 0xcd758f5f, 0x377dc359, 
0x2e5fa4b6, 0x42568e72, 0xb56aacfc, 0xce714a5e, 
0x265cc16e, 0x45d4b3bd, 0xe4f984ef, 0x36c6754c, 
0xccadabef, 0x6b9d23db, 0x8e5f7cd7, 0xeb5bcc71, 
0x74661b5b, 0x8aef6b4e, 0xa97ae196, 0x5a4e379d, 
0xc9708d6f, 0xe49deeba, 0x9ef1acde, 0x3f5d5319, 
0xae5637d7, 0xe71ad377, 0xc9d4312c, 0xb62bb75a, 
0x714dd770, 0x1bda59ae, 0x4a7ba55f, 0x8f7beb5a, 
0xce1589ee, 0xb77be319, 0x5a73b7c6, 0xe6d8ad57, 
0xb4928d8b, 0x95ab9a62, 0x728b5675, 0x38b692bd, 
0xc6c39163, 0xf74c6f8b, 0x9d6ec1c5, 0x2978ce91, 
0x47db159e, 0x3b79d739, 0xd6b46f18, 0xc6276dd6, 
0x98f9828b, 0xe9ded49a, 0xc2b28ddc, 0xf6be659c, 
0xae5f1b46, 0x293bd68c, 0x7cb9d58e, 0x6b1aae31, 
0x34a4335a, 0xc36b0a67, 0x28ba49ac, 0x49ca098c, 
0xc2f7656c, 0xd3b2a75a, 0xad6cb9d9, 0xeb37c66f, 
0xbcd2f5ac, 0x50546e69, 0x16bcb1c2, 0x651ec7d2, 
0x2d5b5af7, 0x4a4eea8b, 0x6730cd71, 0x13b92f99, 
0x9d7166d6, 0xe348df0a, 0x7cdab7a4, 0xef1aaea5, 
0xdbcdad6b, 0xadb5bdcb, 0xaf9b62b7, 0x5a4b37a6, 
0xd6d76d1d, 0xb5a5eb6c, 0x6d90bac2, 0xee99d695, 
0xd9d135ac, 0xe2918e68, 0x59be2599, 0xc6397a2a, 
0xab7a3b57, 0x89668fa5, 0x52b3b5b3, 0xb4a464f9, 
0x7d0f584e, 0x67183e4b, 0x58d6f583, 0xe4b3b4ef, 
0xf6dcf169, 0xb66ccaa6, 0xedc8e39b, 0x6841f6cd, 
0xd295a5ab, 0xd4ada147, 0x99a38b4e, 0xeb28d171, 
0x459f2c9a, 0xbd366d6f, 0x56ae64bb, 0x85736d57, 
0x29cbcd92, 0x2b575ade, 0xc995538b, 0xd78d5992, 
0x955d25d1, 0x277a4277, 0x6bceaf5b, 0xd6396573, 
0x15ac6742, 0xb6f74de7, 0xc95a42fa, 0xeede9ccc, 
0x52f8a670, 0x988da17b, 0x9c6d6ce6, 0x555ace14, 
0x48e115ad, 0x4e768c6d, 0xb3acdb7b, 0xa56afbce, 
0xb79d6afa, 0xca6b31c5, 0x6a7ad62e, 0xf3b5af9b, 
0x94a2f84a, 0xeb4941f0, 0x594e3745, 0xb62b7d5b, 
0xb5bbe757, 0x8c935bb6, 0x670cceb1, 0x8bd6549d, 
0xe25abdb5, 0x6eb4eeed, 0x4d281856, 0x70ec4ed6, 
0x7a5ef6b5, 0x4eb59227, 0x3782e75a, 0xbceaf9de, 
0xa87ad26f, 0x19cb3593, 0x5317b6b1, 0xb264a8e8, 
0xb6275852, 0xaf3a5ab3, 0xfad2d1b2, 0xc6afac22, 
0x75ab5f58, 0xade73ace, 0xdf364711, 0x2b4e74aa, 
0x61d0d4ab, 0xf475290a, 0x83a69a52, 0x2ed95232, 
0x19aa87a4, 0x25b7046b, 0xf7746b78, 0xbcdf784e, 
0x772bdeb1, 0x7a68bab6, 0x8658b633, 0xf2b6714d, 
0x74630a41, 0xe8ca3e52, 0x493eb2b3, 0xc6f37ae7, 
0xf6ad6f26, 0x8af346b6, 0x339b5ef5, 0x77c315c8, 
0x6af2a631, 0x53a4b35a, 0x94ab1b5a, 0xa115a2a3, 
0xd4ae4a9c, 0xdecf3d6a, 0xb37deb4a, 0x5cef39d6, 
0x6b48572a, 0x6c4804a5, 0x5292c4a9, 0x555b9d66, 
0x891558d2, 0x2119b2c7, 0x59b0b16a, 0x46b780e7, 
0xb79ce77a, 0xb37568de, 0x29184f2e, 0x89cb5784, 
0x5dd2b425, 0xef8526ea, 0x9be2a7b1, 0x56c8264c, 
0x39d5ed7a, 0x86758d67, 0x2ba26759, 0x7d6287d6, 
0x2b4589af, 0x4a5d92a5, 0x4216b3a5, 0xcc83a14a, 
0x941cd739, 0xe318ba2d, 0x5ad673a2, 0xceb7aceb, 
0x2dacdb7a, 0x7126b7b9, 0xa94b5254, 0x4b4ad4a5, 
0x391294a9, 0x0d5a1028, 0x7d6b17ce, 0x6b5ac6f5, 
0x39deb5ad, 0x2e2c1ceb, 0xd06522b5, 0xb52d4b52, 
0xa92a52d4, 0x97a19044, 0xc5ed8b98, 0xb5aceb3a, 
0x9d6f5ace, 0xe738d6b5, 0x2838eb2b, 0x52d4a529, 
0x14b5a96b, 0x6320e94a, 0x631891cb, 0x59d6359c, 
0xcef5aceb, 0xf3ad6b5a, 0x8352b8c5, 0xa96a5214, 
0x4a5ad4b5, 0x899284a9, 0x317b54c1, 0xad6739ce, 
0x6b5aceb5, 0xdaceb5ad, 0x40a76c5e, 0x94a5a509, 
0xa5ad6a5a, 0x14094a54, 0x38c4ee23, 0xd6b3ace7, 
0xb59cef59, 0x8c673ad6, 0x2106adef, 0x4b5294a4, 
0x5294b5ad, 0x2a61a529, 0x9ce717b0, 0xeb59d6b3, 
0x59d6b5ac, 0xbe318d67, 0x928414d4, 0xb52d4a4a, 
0xa14a52d4, 0xd6291074, 0xd6358c5e, 0xb5ad6759, 
0x9ce73ace, 0x9af6bdf3, 0x494a5083, 0x5a94a529, 
0x1094290a, 0x8b5a85aa, 0xeb39ce71, 0x58d675ac, 
0xbe338ce7, 0x0e730698, 0x9525294a, 0x29295294, 
0x66320e94, 0xbe6f7bc6, 0xb39ce739, 0x8ce739ce, 
0x8697be31, 0x29420e72, 0x4a5494a5, 0xce942529, 
0x7a504739, 0xe339c62f, 0x38d6739c, 0xae318c67, 
0xce72d695, 0x94a12749, 0x25294a52, 0x87321084, 
0xbdef7854, 0x739c6719, 0x8ce339ce, 0x52b5b631, 
0x08420e69, 0x4a5094a1, 0xce842529, 0x5ad0c639, 
0x6718c5af, 0x18ce738c, 0xae318be7, 0x04790636, 
0x84a1083a, 0x2d094212, 0x061d9352, 0xca3484df, 
0x358ce8da, 0x4be71a2e, 0xd532a130, 0xc8420d74, 
0x42129424, 0x0c439d07, 0x7c52d595, 0xe318be31, 
0xf8bde18c, 0x352d3b52, 0x927394a8, 0x54250631, 
0x5028320d, 0x58b94c41, 0xa62f8bd2, 0x2d7b5f17, 
0x5a50d3c4, 0x9aa53824, 0xc7b24853, 0x30cc631c, 
0x2752d024, 0x7b46f3b1, 0xdad725eb, 0x66adc80b, 
0x31a1010a, 0x43339cf8, 0x7ad0d74c, 0xa2a5b4ce, 
0xb609b04b, 0x95804056, 0xa25a5015, 0x2b44f728, 
0x16a430e4, 0x15b48b23, 0x81646955, 0x89434eb2, 
0x1a5a25a4, 0x40b1a9ab, 0x43a44363, 0x010848d2, 
0xe3424c42, 0x535445a8, 0xd4d4a861, 0x9399ac7a, 
0x25093986, 0x2c4854c1, 0x518e9309, 0xd863a96a, 
0xb4196a21, 0x88282a84, 0x0b420e32, 0x41d66315, 
0xc6a41528, 0x31a84752, 0x086a2244, 0x44480a82, 
0x5106009c, 0x4a64008b, 0x31086812, 0xa84941ca, 
0x6a3a8482, 0x12cc1631, 0x482425a5, 0x6398a64a, 
0x0907598e, 0x6841c442, 0x2a905200, 0x8a70148a, 
0x00002311, 0x14c62a46, 0x43198270, 0x01821310, 
0x04510ca3, 0x1014403a, 0x90052908, 0x6831c231, 
0x18c8500c, 0xc0300d48, 0x5100a339, 0x8c0201c4, 
0x0619c621, 0x210c5108, 0x4c200065, 0x00880049 };
#endif
