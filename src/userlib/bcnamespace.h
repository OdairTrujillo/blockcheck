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
    Name = 2,
    Addrs = 3,
    State = 4,
    City = 5,
    LRep = 6,
    Mail = 7,
    Cel = 8,
    Tel = 9
};
}

namespace Quots {
enum {
    Id = 0,
    Date = 1,
    Name = 2,
    Addrs = 3,
    State = 4,
    City = 5,
    Ctact = 6,
    Cel = 7,
    Mail = 8,
    InspTyp = 9,
    Use = 10,
    VLev = 11,
    Capac = 12,
    Phase = 13,
    PrjArea = 14,
    AreaTyp  = 15,
    NetTyp = 16,
    NetLong = 17,
    Boxes = 18,
    Scope = 19,
    Thrd = 20,
};
}

namespace Props {
enum {
    Id = 0,
    Date = 1,
    Scope = 2,
    Value = 3,
    Iva = 4,
    Viat = 5,
    TotVal = 6,
    LName = 7,
    UsPerc = 8,
    PayWay = 9,
    Aprov = 10,
    AprovD = 11,
    Observ = 12,
    QuotId = 13,
};
}

namespace Sos {
enum {
    Id = 0,
    Date = 1,
    InspName = 2,
    InspPerc = 3,
    AssignD = 4,
    Scope = 5,
    Observ = 6,
    EngObserv = 7,
    AdmObserv = 8,
    AccProc = 9,
    DocProc = 10,
    EngProc = 11,
    BillNumb = 12,
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
