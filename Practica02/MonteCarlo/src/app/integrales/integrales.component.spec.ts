import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { IntegralesComponent } from './integrales.component';

describe('IntegralesComponent', () => {
  let component: IntegralesComponent;
  let fixture: ComponentFixture<IntegralesComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ IntegralesComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(IntegralesComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
