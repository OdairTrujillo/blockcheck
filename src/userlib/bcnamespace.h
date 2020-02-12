#ifndef BCNAMESPACE_H
#define BCNAMESPACE_H

namespace BcNames {
enum {
    EditDesigners = 0,
    EditConstructors = 1,
    EditAuditors = 2,
    EditUsers = 3,
    EditInspectors = 4
};

}

namespace BcProcs {
enum {
    Generacion = 1,
    Transmision = 2,
    Transformacion = 3,
    Distribucion = 4,
    UsoFinal = 5,
    AlumbradoExt = 6,
    AlumbradoInt = 7,
    Especiales = 8,
    NormasVol = 9
};
}

namespace BcUses {
enum {
    Residencial = 1,
    Comercial = 2,
    Industrial = 3,
    Oficial = 4,
    Especiales = 5,
    Rural = 6,
    Urbano = 7,
    AisladaDelSIN = 8,
    ServicioPublico = 9,
    ServicioPrivado = 10,
    UsoGeneral = 11,
    UsoExclusivo = 12,
    ServicioGeneral = 13,
    AlumbradoPublico = 14
};
}

namespace Thrds {
enum {
    Id = 0,
    Nit = 1,
    SName = 2,
    LRep = 3,
    Addrs = 4,
    Mail = 5,
    Cel = 6,
    Tel = 7,
    State = 8,
    City = 9
};
}

namespace Quots {
enum {
    Id = 0,
    Date = 1,
    Name = 2,
    Scope = 3,
    Contact = 4,
    Addrs = 5,
    Mail = 6,
    Cel = 7,
    State = 8,
    City = 9,
    Use = 10,
    InspType = 11,
    NewId = 12
};
}

namespace Props {
enum {
    Id = 0,
    quotId = 1,
    Scope = 2,
    Date = 3,
    ValueMoney = 4,
    PayWay = 5,
    UserPerc = 6,
    PState = 7,
    Aproval = 8,
    City = 9,
    Addrs = 10,
    InstName = 11,
    UserLName = 12,
    thrdNit = 13,
    thrdName = 14,
    Observ = 15,
    Iva = 16,
    Viatic = 17,
    TotVal = 18,
    userCel = 19,
    userMail = 20,
    Value = 21
};
}

namespace Sos {
enum {
    Id = 0,
    Date = 1,
    Scope = 2,
    Observ = 3,
    AccProc = 4,
    DocProc = 5,
    EngProc = 6,
    EngObserv = 7,
    AdmObserv = 8,
    InspPerc = 9,
    AssignD = 10,
    BillNumb = 11,
    InspName = 12,
    propId = 13
};
}

namespace Inspct {
enum {
    Id = 0,
    IDate = 1,
    IState = 2,
    Observ = 3,
    Address = 4,
    Owner = 5,
    State = 6,
    City = 7,
    Constructor = 8,
    ConstMP = 9,
    Auditor = 10,
    AudMP = 11,
    IDictum = 12,
    SoId = 13,
    ADate = 14
};
}

namespace Users {
enum {
    Id = 0,
    Name = 1,
    Passwd = 2,
    LName = 3,
    Charge = 4,
    Level = 5,
    Addrs = 6,
    Mail = 7,
    Cel = 8,
    Tel = 9,
    Availb = 10,
    Perc = 11,
    Nit = 12
};
}

namespace Insp {
enum {
    Id = 0,
    Name = 1,
    Mp = 2,
    Addrs = 3,
    Mail = 4,
    Cel = 5,
    Tel = 6,
    Availb = 7,
    Perc = 8,
    Nit = 9
};
}

namespace SoValue {
enum {
    User = 0,
    Insp = 1
};
}

namespace SoState {
enum {
    PropId = 0,
    PropDate = 1,
    SoId = 2,
    SoDate = 3,
    QScope = 4,
    PScope = 5,
    SScope = 6,
    InspName = 7,
    ADate = 8,
    RDate = 9,
    DocProc = 10,
    AccProc = 11,
    EngProc = 12,
    SDate = 13,
    AdmObserv = 14,
    EngObserv = 15,
    PropTValue = 16
};
}

namespace SoTrck {
enum {
    ReceiptDate = 0,
    ReceiverName = 1,
    ShippingDate = 2,
    ShipperName = 3,
    ShippingName = 4,
    ShippingCompany = 5,
    GuideNumber = 6,
    Observ = 7,
    ShippingState = 8,
    ShippingCity = 9,
    InspName = 10
};
}


#endif // BCNAMESPACE_H
